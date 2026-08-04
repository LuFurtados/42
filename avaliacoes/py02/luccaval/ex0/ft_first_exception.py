def input_temperature(temp_str: str) -> int:
    temp_int = int(temp_str)
    return temp_int


def test_temperature() -> None:
    print("=== Garden Temperature ===")
    print()
    temp = '25'
    print(f"Input data is '{temp}'")
    try:
        temp_int = input_temperature(temp)
        print(f"Temperature is now {temp_int}°C")
        print()
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")
    temp = '30'
    print(f"Input data is '{temp}'")
    try:
        temp_int = input_temperature(temp)
        print(f"Temperature is now {temp_int}°C")
        print()
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")
        print()
    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature()
