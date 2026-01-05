import time
import random
import os

TICK_TIME = 0.5
HOTEL_SIZE = 12
POPULATION = 3

class Hotel:
    def __init__(self, name, floors_count):
        self.name = name
        self.size = 0
        self.floors = []
        self.elevators = []
        
        self.add_floors(floors_count)
        
    def add_floors(self, quantity):
        for _ in range(quantity):
            self.add_floor()
    
    def add_floor(self):
        floor = Floor(self)
        self.floors.append(floor)
        self.size += 1

    def add_elevator(self, name, capacity):
        bottom_floor = self.floors[0]
        elevator = Elevator(self, bottom_floor, name, capacity)
        self.elevators.append(elevator)

    def tick_main(self):
        for _ in range(POPULATION):
            floor_number = random.randint(0, self.size - 1)
            floor = self.floors[floor_number]
            floor.add_random_person()
        
        for elevator in self.elevators:
            elevator.tick_main()
    
    def display(self):
        output = "\033[H"
        output += f"--- {self.name} ---\033[K\n"
        
        for floor in self.floors[::-1]:
            if floor == self.floors[0]:
                row = f"Floor_{floor.number:02} {floor.up:2}↑    "
            elif floor == self.floors[-1]:
                row = f"Floor_{floor.number:02}     {floor.down:2}↓"
            else:
                row = f"Floor_{floor.number:02} {floor.up:2}↑ {floor.down:2}↓"
            
            row += " |"
            
            for elevator in self.elevators:
                if elevator.floor == floor:
                    queue = elevator.get_queue()
                    row += f" [{elevator.name}: {elevator.people}/{elevator.capacity} -> {queue}]"
            
            output += row + "\033[K\n"
            
        print(output, end="", flush=True)

class Elevator:
    def __init__(self, hotel, floor, name, capacity):
        self.hotel = hotel
        self.floor = floor
        self.name = name
        
        self.capacity = capacity
        self.people = 0
        self.direction = 1 # 1: Up, 2: Down
        self.floors_to_go = [0 for _ in range(self.hotel.size)]
        
    def move_up(self):
        number = self.floor.number
        if number == self.hotel.size - 1:
            return False
        
        next_floor = self.hotel.floors[number + 1]
        self.floor = next_floor
        return True
        
    def move_down(self):
        number = self.floor.number
        if number == 0:
            return False

        next_floor = self.hotel.floors[number - 1]
        self.floor = next_floor
        return True

    def get_queue(self):
        queue = []
        for floor_number, people in enumerate(self.floors_to_go):
            if people > 0:
                queue.append(floor_number)
        
        return tuple(queue)

    def tick_main(self):
        if self.people_to_leave():
            self.remove_people()
            return
        
        if self.people_to_get():
            self.get_people_from_floor()
            return
        
        self.tick_move()

    def tick_move(self):
        if self.direction == 1:
            self.move_up()
        else:
            self.move_down()
        
        if self.floor.number == 0:
            self.direction = 1
        elif self.floor == self.hotel.floors[-1]:
            self.direction = 2
    
    def remaining_capacity(self):
        return self.capacity - self.people
    
    def people_to_get(self):        
        if self.direction == 1:
            people = self.floor.up
        elif self.direction == 2:
            people = self.floor.down
        
        
        total_people_to_get = min(self.remaining_capacity(), people)
        return total_people_to_get
        
    def people_to_leave(self):
        floor_number = self.floor.number
        people = self.floors_to_go[floor_number]
        return people
        
    def remove_people(self):
        floor_number = self.floor.number
        people = self.floors_to_go[floor_number]
        
        self.floors_to_go[floor_number] -= people
        self.people -= people
    
    def get_people_from_floor(self):
        min_number = 0
        max_number = self.hotel.size - 1
        
        capacity_remaining = self.capacity - self.people
        total_people_to_get = 0
        if self.direction == 1: # UP
            min_number = self.floor.number + 1
            total_people_to_get = min(self.floor.up, capacity_remaining)
            self.floor.up -= total_people_to_get
        elif self.direction == 2: # DOWN
            max_number = self.floor.number - 1
            total_people_to_get = min(self.floor.down, capacity_remaining)
            self.floor.down -= total_people_to_get
        
        self.people += total_people_to_get
        for _ in range(total_people_to_get): 
            floor_number = random.randint(min_number, max_number)
            self.floors_to_go[floor_number] += 1
    
    def add_people(self, people, direction):
        min_number = 0
        max_number = self.hotel.size - 1
        
        if direction == 1: # UP
            min_number = self.floor.number + 1
        elif direction == 2: # DOWN
            max_number = self.floor.number - 1
        
        for _ in range(people): 
            floor_number = random.randint(min_number, max_number)
            
            self.floors_to_go[floor_number] += 1
    
class Floor:
    def __init__(self, hotel):
        self.hotel = hotel
        self.number = hotel.size
        self.up = 0
        self.down = 0
        
    def add_people(self, up, down):
        self.up += up
        self.down += down  
        
    def add_random_person(self):
        people_up = 0
        people_down = 0
        if self.number == 0: # Bottom floor
            people_up = 1
        elif self.number == self.hotel.size - 1: # Top floor
            people_down = 1
        else: # Mid Floor
            people_up = random.randint(0, 1)
            people_down = 1 - people_up

        self.add_people(people_up, people_down)      

def main():
    os.system('cls' if os.name == 'nt' else 'clear')
    global_tick = 0
    hotel = Hotel("Python Hotel", HOTEL_SIZE)
    hotel.add_elevator("Leap", 20)
    hotel.add_elevator("Lurk", 3)
    
    
    while True:
        hotel.display()
        hotel.tick_main()
        time.sleep(TICK_TIME)
        global_tick += 1

if __name__ == "__main__":
    main()