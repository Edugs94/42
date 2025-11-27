class SecurePlant:
    def __init__(self, name):
        self.name = name
        self._height = 0
        self._age = 0

    @property
    def height(self):
        return self._height

    @property
    def age(self):
        return self._age

    @height.setter
    def height(self, new_height):
        if (new_height < 0):
            print(
                f"Invalid operation attempted: height {new_height}cm"
                " [REJECTED]"
                )
            print("Security: Negative height rejected")
        else:
            self._height = new_height
            print(f"Height updated: {new_height}cm [OK]")

    @age.setter
    def age(self, new_age):
        if (new_age < 0):
            print(
                f"Invalid operation attempted: age {new_age} days"
                " [REJECTED]"
                )
            print("Security: Negative age rejected")
        else:
            self._age = new_age
            print(f"age updated: {new_age} days [OK]")

    def display_info(self):
        print(f"Plant created: {self.name}")
        print(f"Current plant: {self.name} ({self.height}cm, {self.age} days)")


def ft_garden_security():
    print("=== Garden Security System ===")
    my_rose = SecurePlant("Rose")
    print(f"Plant created: {my_rose.name}")
    my_rose.height = 25
    my_rose.age = 30
    my_rose.height = -5
    print(f"Current plant: {my_rose.name} ({my_rose.height}"
          f"cm, {my_rose.age} days)")


ft_garden_security()
