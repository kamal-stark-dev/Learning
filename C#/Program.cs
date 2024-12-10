// making an information management system
Console.Title = "Student IMS";

/*
Objective -
1. Create a class "Student"
2. Add private fields -> name, address, email and grades(0-100)
3. Add a teacher login and validation
4. If valid teacher then they can modify students grades
5. Constructor that initializes student's detail
6. Add functions like "display_info()" and "isPassing()"
7. Throws exception when the grade is accessed outside the allowed range
*/

Student Hopper = new Student("22bai71322", "Parry Hopper", "Berlin", "parry@hopper.in", 89);
Hopper.display_info();
Hopper.edit_grades(91);
Hopper.display_info();

Console.ReadKey();

class Student
{
    public string uid;
    public string name;
    private string address;
    private string email;
    private double grades;

    public Student(string _uid, string _name, string _address, string _email, double _grades)
    {
        uid = _uid;
        name = _name;
        address = _address;
        email = _email;
        grades = _grades;
    }

    public void display_info()
    {
        string information = $"Name: {name}    UID: {uid}    City: {address}    Email: {email}    Grade: {grades}";
        Console.WriteLine(information);
    }

    public void edit_grades(double _grades)
    {
        grades = _grades;
        Console.WriteLine($"Successfully modified {name}'s grades to {grades}.");
    }
}