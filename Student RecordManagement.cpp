# Student Record Management using 1D and 2D Arrays

# 1D arrays for storing individual attributes
roll_no = []
name = []
marks = []

# 2D array for storing complete student records
students = []


# Function to insert a student record
def insert_student():
    r = int(input("Enter Roll Number: "))
    n = input("Enter Name: ")
    m = float(input("Enter Marks: "))

    # Store in 1D arrays
    roll_no.append(r)
    name.append(n)
    marks.append(m)

    # Store in 2D array
    students.append([r, n, m])

    print("Student record inserted successfully.")


# Function to display student records
def display_students():
    if len(students) == 0:
        print("No student records available.")
        return

    print("\nRoll No.\tName\t\tMarks")
    print("-----------------------------------")

    for student in students:
        print(f"{student[0]}\t\t{student[1]}\t\t{student[2]}")


# Function to search a student by roll number
def search_student():
    r = int(input("Enter Roll Number to search: "))

    for i in range(len(students)):
        if students[i][0] == r:
            print("\nStudent Found!")
            print("Roll No :", students[i][0])
            print("Name    :", students[i][1])
            print("Marks   :", students[i][2])
            return

    print("Student record not found.")


# Function to delete a student by roll number
def delete_student():
    r = int(input("Enter Roll Number to delete: "))

    for i in range(len(students)):
        if students[i][0] == r:

            # Delete from 2D array
            students.pop(i)

            # Delete from corresponding 1D arrays
            roll_no.pop(i)
            name.pop(i)
            marks.pop(i)

            print("Student record deleted successfully.")
            return

    print("Student record not found.")


# Main menu
while True:
    print("\n===== STUDENT RECORD MANAGEMENT =====")
    print("1. Insert Student")
    print("2. Display Students")
    print("3. Search Student")
    print("4. Delete Student")
    print("5. Exit")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        insert_student()

    elif choice == 2:
        display_students()

    elif choice == 3:
        search_student()

    elif choice == 4:
        delete_student()

    elif choice == 5:
        print("Program terminated.")
        break

    else:
        print("Invalid choice. Please try again.")
