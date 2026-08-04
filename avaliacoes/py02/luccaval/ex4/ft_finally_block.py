class GardenError(Exception):
    def __init__(self, message: str = "Garden error ocurred") -> None:
        super().__init__(message)


class PlantError(GardenError):
    def __init__(self, message: str = "Unknown plant error") -> None:
        super().__init__(message)


def water_plant(plant_name: str) -> None:
    if not plant_name[0].isupper():
        raise PlantError(f" Invalid plant name to water: '{plant_name}'")
    print(f"Watering {plant_name}: [OK]")


def test_watering_system(test_name: str, plants_to_water: list) -> None:
    print(f"Testing {test_name}...")
    print("Opening watering system")
    try:
        for plant in plants_to_water:
            water_plant(plant)
    except PlantError as e:
        print(f"Caught PlantError: {e}")
        print(".. ending tests and returning to main")
        return
    finally:
        print("Closing watering system")


if __name__ == "__main__":
    print("=== Garden Watering System ===")
    print()
    test_watering_system("valid plants", ["Tomato", "Lettuce", "Carrots"])
    print()
    test_watering_system("invalid plants", ["Tomato", "lettuce"])
    print()
    print("Cleanup always happens, even with errors!")
