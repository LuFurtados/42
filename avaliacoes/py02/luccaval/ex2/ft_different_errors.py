def garden_operations(operation_number: int) -> str:
    if operation_number == 0:
        int("abc")
    elif operation_number == 1:
        10 / 0
    elif operation_number == 2:
        open("/non/existent/file")
    elif operation_number == 3:
        n = 10
        "abc" + n  # type: ignore[operator]
    else:
        return "Operation completed successfully"
    return "test"


def test_error_types() -> None:
    print("=== Garden Error Types Demo ===")
    i = 0
    print(f"Testing operation {i}...")
    try:
        result = garden_operations(i)
        print(result)
    except ValueError as e:
        print(f"Caught ValueError: {e}")

    i = 1
    print(f"Testing operation {i}...")
    try:
        result = garden_operations(i)
        print(result)
    except ZeroDivisionError as e:
        print(f"Caught ZeroDivisionError: {e}")

    i = 2
    print(f"Testing operation {i}...")
    try:
        result = garden_operations(i)
        print(result)
    except FileNotFoundError as e:
        print(f"Caught FileNotFoundError: {e}")

    i = 3
    print(f"Testing operation {i}...")
    try:
        result = garden_operations(i)
        print(result)
    except TypeError as e:
        print(f"Caught TypeError: {e}")

    i = 4
    print(f"Testing operation {i}...")
    try:
        result = garden_operations(i)
        print(result)
    except (ValueError, ZeroDivisionError, FileNotFoundError, TypeError) as e:
        print(f"Caught error in combined block: {e}")

    print()
    print("All error types tested successfully!")


if __name__ == "__main__":
    test_error_types()
