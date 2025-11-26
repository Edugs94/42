class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age

    def grow(self, day, growth_rate):
        self.height += (day - 1) * growth_rate

    def age(self, day):
        self.age += day - 1

    def get_info(self, day):
        if day == 1:
            print(f"=== Day {day} ===")
            print(f"{self.name}: {self.height}cm, {self.age} days old")
        elif day == 7:
            print(f"=== Day {day} ===")
            print(f"{self.name}: {self.height}cm, {self.age} days old")
            print(f"Growth this week: +{self.height}cm")


rose = Plant("Rose", 25, 30)
sunflower = Plant("Sunflower", 80, 45)
cactus = Plant("Cactus", 15, 120)


def ft_plant_growth(self, growth_rate):
    plant_obj.get_info(1)
    
    days_to_simulate = 7

    plant_obj.grow(days_to_simulate, growth_rate)
    plant_obj.increase_age(days_to_simulate)

    plant_obj.get_info(7)
    
    print("-" * 20)


ft_plant_growth(rose, 1)
ft_plant_growth(sunflower, 3)
ft_plant_growth(cactus, 2)
