# Create a symetrical matrix with random values and diagonal values as 0.
#
# Input: n - size of the matrix
# Output: matrix - the matrix
# Example 1:
# input: 3
# output:
# 0 2 3
# 2 0 5
# 3 5 0
# Example 2:
# input: 5
# output:
# 0 1 7 3 4
# 1 0 3 4 5
# 7 3 0 11 1
# 3 4 11 0 5
# 4 5 1 5 0
# Example 3:

import random

def create_symetrical_matrix(n):
    """
    input: 6
    output:
            0 8 3 10 4 7
            8 0 15 7 9 6
            3 15 0 6 6 3
            10 7 6 0 5 4
            4 9 6 5 0 9
            7 6 3 4 9 0
    """
    # Initialize the matrix
    matrix = [[0 for x in range(n)] for y in range(n)]
    # Fill the matrix with random values
    for i in range(n):
        for j in range(n):
            if i == j:
                # Diagonal values are 0
                matrix[i][j] = 0
            else:
                # Fill half of the matrix with random values
                matrix[i][j] = random.randint(1, 100)
                matrix[j][i] = matrix[i][j]


    return matrix

def main():
    n = int(input("Enter the size of the matrix: "))
    matrix = create_symetrical_matrix(n)
    for i in range(n):
        for j in range(n):
            print(matrix[i][j], end=" ")
        print()
    
    # Save the matrix to a txt file
    with open(f"matrix_{n}.txt", "w") as f:
        for i in range(n):
            for j in range(n):
                f.write(str(matrix[i][j]) + " ")
            f.write("\n")


if __name__ == "__main__":
    main()

