import csv

with open("phonebook.csv", "a") as file:
    name = input("Name: ")
    number = input("Number: ")

    writer = csv.DicWriter(file, fieldnames=["name", "number"])
    writer.writerow({"name": name, "number": number})
