def input_temperature(temp_str: str) -> int:
    temp_int = int(temp_str)
    if 0 <= temp_int <= 40:
        return temp_int
    elif temp_int < 0:
        raise ValueError(f"{temp_int}°C is too cold for plants (min 0°C)")
    else:
        raise ValueError(f"{temp_int}°C is too hot for plants (max 40°C)")


def test_temperature() -> None:
    print("=== Garden Temperature Checker ===")
    print()
    test_cases = ["25", "abc", "100", "-50"]
    for temp in test_cases:
        print(f"Input data is '{temp}'")
        try:
            temp_int = input_temperature(temp)
            print(f"Temperature is now {temp_int}°C\n")
        except ValueError as e:
            print(f"Caught input_temperature error: {e}\n")

    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature()
