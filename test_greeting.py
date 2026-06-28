import sys
from show_greeting import greeting  # Assuming show_greeting.py is in the same directory

def test_greeting():
    expected_output = "Hey my_test"
    actual_output = greeting("my_test")
    assert actual_output == expected_output, f"Expected '{expected_output}', got '{actual_output}'"

if __name__ == '__main__':
    test_greeting()
