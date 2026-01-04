import time
import random

TICK_TIME = 0.5 # seconds

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
        floor_number = random.randint(0, self.size - 1)
        floor = self.floors[floor_number]
        floor.add_random_person()
        
        for elevator in self.elevators:
            elevator.tick_main()
    
    def display(self):
        print("\n"*20)
        print(f"--- {self.name} ---")
        for floor in self.floors[::-1]:
            print(f"Floor_{floor.number} {floor.up:2}↑ {floor.down:2}↓", end=" ")
            for elevator in self.elevators:
                if elevator.floor == floor:
                    print(f"[]", end=" ")
            print()
            
class Elevator:
    def __init__(self, hotel, floor, name, capacity):
        self.hotel = hotel
        self.floor = floor
        self.name = name
        self.capacity = capacity
        self.direction = 0 # 0: Stop, 1: Up, 2: Down
        
    def move_up(self):
        number = self.floor.number
        if number == self.hotel.size - 1:
            return
        
        next_floor = self.hotel.floors[number + 1]
        self.floor = next_floor
        
    def move_down(self):
        number = self.floor.number
        if number == 0:
            return
        
        next_floor = self.hotel.floors[number - 1]
        self.floor = next_floor
        
    def open(self):
        ...
        
    def close(self):
        ...
        
    def tick_main(self):
        number = self.floor.number
        if number == 0:
            self.floor = self.hotel.floors[-1]
        else:
            self.move_down()

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
    global_tick = 0
    hotel = Hotel("Python Hotel", 5)
    hotel.add_elevator("Leap", 10)
    
    
    while True:
        hotel.display()
        hotel.tick_main()
        time.sleep(TICK_TIME)
        global_tick += 1

if __name__ == "__main__":
    main()