class GardenError(Exception):
    def __init__(self, message: str = "Garden error ocurred") -> None:
        super().__init__(message)


class PlantError(GardenError):
    def __init__(self, message: str = "Unknown plant error") -> None:
        super().__init__(message)


class WaterError(GardenError):
    def __init__(self, message: str = "Unknown water error") -> None:
        super().__init__(message)


def simulate_plant_problem() -> None:
    raise PlantError("The tomato plant is wilting!")


def simulate_water_problem() -> None:
    raise WaterError("Not enough water in the tank!")


def test_custom_errors() -> None:
    print("=== Custom Garden Errors Demo ===")
    print()
    print("Testing PlantError...")
    try:
        simulate_plant_problem()
    except PlantError as e:
        print(f"Caught PlantError: {e}")
    print()
    print("Testing WaterError...")
    try:
        simulate_water_problem()
    except WaterError as e:
        print(f"Caught WaterError: {e}")
    print()
    print("Testing catching all garden errors...")
    try:
        simulate_plant_problem()
    except GardenError as e:
        print(f"Caught GardenError: {e}")
    try:
        simulate_water_problem()
    except GardenError as e:
        print(f"Caught GardenError: {e}")
    print()
    print("All custom error types work correctly!")


if __name__ == "__main__":
    test_custom_errors()
