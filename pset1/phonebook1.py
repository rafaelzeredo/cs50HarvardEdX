from cs50 import get_string

people = {
    "Carter": "+1-617-495-1000",
    "David": "+1-949-468-2758"
}

name = get_string("Name: ")
if name in people:
    number = people[name]
    print("Number: {number}")