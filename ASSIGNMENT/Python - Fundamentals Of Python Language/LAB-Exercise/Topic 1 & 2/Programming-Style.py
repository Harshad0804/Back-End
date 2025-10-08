"""
A simple Python program demonstrating:
- Proper indentation
- Use of comments
- Variables following PEP 8 guidelines
"""

# Function to calculate the area of a rectangle
def calculate_area(length, width):
    """Return the area of a rectangle."""
    return length * width


# Main part of the program
def main():
    """Main function to demonstrate PEP 8 style."""
    
    # Define variables using lowercase_with_underscores
    rectangle_length = 10
    rectangle_width = 5

    # Calculate area
    area = calculate_area(rectangle_length, rectangle_width)

    # Print the result
    print(f"The area of the rectangle is: {area}")


# Python convention: run main() only if this file is executed directly
if __name__ == "__main__":
    main()
