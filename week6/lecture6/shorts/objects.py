class Student():

    def __init__(self, name, id, nota=None):
        self.name = name
        self.id = id
        self.nota = nota

    def change(self, id):
        self.id = id

    def print(self):
        print(f"{self.name} - {self.id}")


students = []

if __name__ == "__main__":
    qty_students = int(input("Qty. Students: "))

    for student in range(qty_students):
        name = input("\nName: ")
        id = input("Id: ")

        students.append(Student(name, id))
