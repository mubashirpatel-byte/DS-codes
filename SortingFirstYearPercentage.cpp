# Sorting First Year Percentage using Selection Sort and Quick Sort

percentages = []

# Function to enter student percentages
def enter_percentages():
    global percentages

    n = int(input("Enter number of students: "))

    percentages = []

    for i in range(n):
        percentage = float(input("Enter percentage of student {}: ".format(i + 1)))
        percentages.append(percentage)

    print("Percentages stored successfully.")


# Selection Sort
def selection_sort(arr):
    n = len(arr)

    for i in range(n - 1):
        min_index = i

        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j

        # Swap
        arr[i], arr[min_index] = arr[min_index], arr[i]

    return arr


# Quick Sort
def quick_sort(arr):
    if len(arr) <= 1:
        return arr

    pivot = arr[0]

    left = []
    right = []

    for i in range(1, len(arr)):
        if arr[i] <= pivot:
            left.append(arr[i])
        else:
            right.append(arr[i])

    return quick_sort(left) + [pivot] + quick_sort(right)


# Display top five scores
def display_top_five():
    if len(percentages) == 0:
        print("No percentages available.")
        return

    # Sort in descending order
    sorted_scores = sorted(percentages, reverse=True)

    print("\nTop Five Scores:")

    limit = min(5, len(sorted_scores))

    for i in range(limit):
        print("Rank", i + 1, ":", sorted_scores[i])


# Display all percentages
def display_percentages():
    if len(percentages) == 0:
        print("No percentages available.")
    else:
        print("Percentages:")
        print(percentages)


# Main Menu
while True:

    print("\n========== STUDENT PERCENTAGE MENU ==========")
    print("1. Enter Student Percentages")
    print("2. Display Percentages")
    print("3. Sort using Selection Sort")
    print("4. Sort using Quick Sort")
    print("5. Display Top Five Scores")
    print("6. Exit")
    print("=============================================")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        enter_percentages()

    elif choice == 2:
        display_percentages()

    elif choice == 3:
        if len(percentages) == 0:
            print("No percentages available.")
        else:
            selection_sort(percentages)
            print("Sorted using Selection Sort:")
            print(percentages)

    elif choice == 4:
        if len(percentages) == 0:
            print("No percentages available.")
        else:
            percentages = quick_sort(percentages)
            print("Sorted using Quick Sort:")
            print(percentages)

    elif choice == 5:
        display_top_five()

    elif choice == 6:
        print("Program terminated.")
        break

    else:
        print("Invalid choice! Please try again.")