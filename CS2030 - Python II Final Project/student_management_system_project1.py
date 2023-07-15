import json
import re


def read_json(file_name, default_data=[]):
    try:
        # open data.json
        with open(file_name, 'r') as f:
            students = json.load(f)
    # if the data file is not in the same directory as code
    except FileNotFoundError:
        print("Unable to read data file, please ensure it is the correct location. Program will now close.")
        exit(1)
    # if data.json is empty (completely empty, not just [])
    except json.decoder.JSONDecodeError:
        students = default_data

    return students


def write_json(file_name, data):
    # write data to data.json
    try:
        with open(file_name, 'w') as f:
            json.dump(data, f, indent=4)
    # if the data file is not in the same directory as code
    except FileNotFoundError:
        print("Unable to read data file, please ensure it is the correct location.")


def read_file(file_name):
    try:
        with open(file_name, "r", encoding='utf-8') as file:  # open file
            welcome = file.read()  # get the welcome text
    # if welcome file is not in same directory as code
    except FileNotFoundError:
        print("Unable to read menu file, please ensure it is the correct location. Program will now close.")
        exit(1)

    return welcome


def exit_system():
    confirm = input("Do you want to exit ths system? Enter Y to confirm: ")
    if confirm == 'y' or confirm == 'Y':
        return False  # loop = false
    else:
        return True  # loop = true


def start():
    welcome_string = read_file("welcome.txt")

    loop = True
    while loop is True:  # main menu loop
        # read student data from json (inside loop to refresh every time menu is called)
        students = read_json("data.json")
        if len(students) == 0:  # if there are no students, automatically choose 1
            choice = '1'
        else:
            print(welcome_string)  # print menu
            choice = input("Please Enter the Operation Code: ")
        match choice:  # menu choices
            case '1':
                add_user()
            case '2':
                del_user()
            case '3':
                modify_user()
            case '4':
                query_user()
            case '5':
                display_user()
            case '6':
                loop = exit_system()
            case default:
                print("Incorrect option, please try again")
                loop = True


def add_user():
    # read student data from json
    students = read_json("data.json")

    print("======================Add Student===========================\n"
          "\t1. The first letter of the first and last name must be capitalized\n"
          "\t2. The first and last name must each have at least two letters\n"
          "\t3. No digits allowed in the name\n"
          "\t4. The student ID is 6 digits long and must start with 700\n"
          "\t5. The phone number must be in the (xxx-xxx-xxxx) format\n"
          "\t6. The student's major must be in CS, CYBER, SE, IT, or DS\n")

    # validate ID loop
    valid_id = False
    while not valid_id:
        try:
            id = input("Please enter the student ID: ")

            # test for 700xxx format
            if not re.fullmatch(r'700\d{3}', id):
                raise RuntimeError("\u274C Invalid student ID.")

            # search for ID in students
            for x in students:
                if id == x["ID"]:  # check for ID in list
                    raise RuntimeError("\u274C This student ID already exists in the system.")

        except RuntimeError as ex:
            print(ex)
        else:
            valid_id = True

    # validate name loop
    valid_name = False
    while not valid_name:
        try:
            name = input("Please enter the student name (First, Last): ")

            # first and last only
            names = name.split(' ')
            if len(names) != 2:
                raise RuntimeError("\u274C First and last name only.")

            # checks for uppercase in name/name length
            if not re.fullmatch("^[A-Z][a-zA-Z]+", names[0]) or not re.fullmatch("^[A-Z][a-zA-Z]+", names[1]):
                raise RuntimeError("\u274C Invalid name.")

        except RuntimeError as ex:
            print(ex)
        else:
            valid_name = True

    # validate phone loop
    valid_phone = False
    while not valid_phone:
        phone = input("Please enter the student phone \u260E: ")
        try:
            # Check phone format matches xxx-xxx-xxxx (digits only)
            if not re.fullmatch(r"\d{3}-\d{3}-\d{4}", phone):
                raise RuntimeError("\u274C Invalid phone number format.")
        except RuntimeError as ex:
            print(ex)
        else:
            valid_phone = True

    # validate major loop
    valid_major = False
    while not valid_major:
        major = input("Please enter the student major: ").upper()
        try:
            # check major
            if major not in ["CS", "CYBR", "SE", "IT", "DS"]:
                raise RuntimeError("\u274C Invalid major.")
        except RuntimeError as ex:
            print(ex)
        else:
            valid_major = True

    print("\u2714 New student record has been added")
    # add new student dict to list
    students.append({"ID": id, "Name": name, "Phone": phone, "Major": major})
    write_json("data.json", students)


def modify_user():
    # read student data from json
    students = read_json("data.json")

    # loop until correct student ID has been entered
    found = False
    while not found:
        id = input("Please enter the student ID record you want to modify: ")
        for student in students:  # loop through students
            if id == student["ID"]:  # check if student is in list
                old_student = student
                found = True
        if not found:
            print("\t\u274C The student ID " + id + " record does not exist")

    idx = students.index(old_student)

    # validate name loop
    valid_name = False
    while not valid_name:
        name = input("New name: (press enter to continue without modifying) ")
        name = cus_input(old_student["Name"], name)
        try:
            # first and last only
            names = name.split(' ')
            if len(names) != 2:
                raise RuntimeError("\u274C First and last name only.")

            # checks for uppercase in name/name length
            if not re.fullmatch("^[A-Z][a-zA-Z]+", names[0]) or not re.fullmatch("^[A-Z][a-zA-Z]+", names[1]):
                raise RuntimeError("\u274C Invalid name.")

        except RuntimeError as ex:
            print(ex)
        else:
            valid_name = True

    # validate phone loop
    valid_phone = False
    while not valid_phone:
        phone = input("New phone \u260E: (press enter to continue without modifying) ")
        phone = cus_input(old_student["Phone"], phone)
        try:
            # Check phone format matches xxx-xxx-xxxx (digits only)
            if not re.fullmatch(r"\d{3}-\d{3}-\d{4}", phone):
                raise RuntimeError("\u274C Invalid phone number format.")
        except RuntimeError as ex:
            print(ex)
        else:
            valid_phone = True

    # validate major loop
    valid_major = False
    while not valid_major:
        major = input("New major: (press enter to continue without modifying) ").upper()
        major = cus_input(old_student["Major"],major)
        try:
            # check major
            if major not in ["CS", "CYBR", "SE", "IT", "DS"]:
                raise RuntimeError("\u274C Invalid major.")
        except RuntimeError as ex:
            print(ex)
        else:
            valid_major = True

    students[idx]["Name"] = name
    students[idx]["Phone"] = phone
    students[idx]["Major"] = major

    print(students)
    
    write_json("data.json", students)


def del_user():
    # read student data from json
    students = read_json("data.json")

    id = input("Please enter the student ID record to delete: ")
    found = False
    for student in students:  # loop through students
        if id == student["ID"]:  # check if student is in list, if so, delete
            confirm = input("Are you sure you want to delete the record? Y or N: ")
            if confirm == 'y' or confirm == 'Y':
                students.remove(student)  # remove student dictionary from list
                print("\u2714 Student record deleted")
            found = True
            break
    if not found:
        print("\t\u274C The student ID " + id + " record does not exist")

    write_json("data.json", students)


def query_user():
    # read student data from json
    students = read_json("data.json")

    print("======================Student Record========================")
    id = input("Please enter the student ID you want to query: ")
    for student in students:  # loop through students
        found = False
        if id == student["ID"]:  # check if student is in list
            print("\u2709 ID: " + student["ID"] + ", Name: " + student["Name"] + ", Phone: " + student["Phone"]
                  + ", Major: " + student["Major"])
            found = True
            break
    if not found:
        print("\t\u274C The student ID " + id + " record does not exist")


def display_user():
    # read student data from json
    students = read_json("data.json")

    print("======================Student Records=======================\n"
          "\tID\t\tName\t\t\t\tPhone\t\t\tMajor")
    for student in students:  # loop through students and print each one
        print("\t{0:8}{1:20}{2:16}{3}".format(student["ID"], student["Name"], student["Phone"], student["Major"]))


def cus_input(current_value, message):
    # if input is empty, return previous value
    return current_value if message == '' else message


if __name__ == "__main__":
    start()