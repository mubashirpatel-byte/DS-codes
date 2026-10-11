Program for Library Book Search
# Using Python List

books = []


# Function to store book IDs
def store_books():
    global books

    n = int(input("Enter number of books: "))

    books = []

    for i in range(n):
        book_id = int(input("Enter Book ID: "))
        books.append(book_id)

    # Sort the list
    books.sort()

    print("Book IDs stored successfully.")
    print("Sorted Book IDs:", books)


# Function for Linear Search
def linear_search():
    if len(books) == 0:
        print("No books available.")
        return

    key = int(input("Enter Book ID to search: "))

    for i in range(len(books)):
        if books[i] == key:
            print("Book Available")
            print("Location:", i + 1)
            return

    print("Book Not Available")


# Function for Binary Search
def binary_search():
    if len(books) == 0:
        print("No books available.")
        return

    key = int(input("Enter Book ID to search: "))

    low = 0
    high = len(books) - 1

    while low <= high:
        mid = (low + high) // 2

        if books[mid] == key:
            print("Book Available")
            print("Location:", mid + 1)
            return

        elif books[mid] < key:
            low = mid + 1

        else:
            high = mid - 1

    print("Book Not Available")


# Function to display books
def display_books():
    if len(books) == 0:
        print("No books available.")
    else:
        print("Sorted Book IDs:")
        for i in range(len(books)):
            print("Location", i + 1, ":", books[i])


# Main Menu
while True:

    print("\n========== LIBRARY MENU ==========")
    print("1. Store Book IDs")
    print("2. Display Book IDs")
    print("3. Linear Search")
    print("4. Binary Search")
    print("5. Exit")
    print("==================================")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        store_books()

    elif choice == 2:
        display_books()

    elif choice == 3:
        linear_search()

    elif choice == 4:
        binary_search()

    elif choice == 5:
        print("Program terminated.")
        break

    else:
        print("Invalid choice! Please try again."