#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "students.dat"
#define MAX_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    int id;
    char name[MAX_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    int age;
} student;

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void displayMenu() {
    printf("\n");
    printf("╔══════════════════════════════════════════════╗\n");
    printf("║         🌟 STUDENT MANAGEMENT SYSTEM 🌟      ║\n");
    printf("╠══════════════════════════════════════════════╣\n");
    printf("║  1. 📌 Register a Student                    ║\n");
    printf("║  2. 📋  View All Students                    ║\n");
    printf("║  3. ✏️  Update Student Information           ║\n");
    printf("║  4. ❌ Delete a Student                      ║\n");
    printf("║  5. 🚪 Exit the Program                      ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf("👉 Please enter your choice (1 - 5): ");
}


int getNextId() {
    FILE *file = fopen(FILENAME, "rb");
    student Student;
    int maxId = 0;

    if (file == NULL) {
        return 1;
    }

    while (fread(&Student, sizeof(student), 1, file)) {
        if (Student.id > maxId) {
            maxId = Student.id;
        }
    }

    fclose(file);
    return maxId + 1;
}

void listMenu(){
    
}

void CreateStudent() {
    FILE *file = fopen(FILENAME, "ab");

    if (file == NULL) {
        printf("🚫 Error: Could not open file for writing.\n");
        return;
    }

    student Student;
    printf("\n✨ ============================================ ✨\n");
    printf("🎓 Welcome! Let's add a new student to the system\n");
    printf("✨ ============================================ ✨\n");

    Student.id = getNextId();
    printf("🔖 Assigned Student ID: %d\n", Student.id);

    printf("🧑‍💼 Enter student name: ");
    fgets(Student.name, MAX_LENGTH, stdin);
    Student.name[strcspn(Student.name, "\n")] = 0;

    printf("📧 Enter student email: ");
    fgets(Student.email, MAX_EMAIL_LENGTH, stdin);
    Student.email[strcspn(Student.email, "\n")] = 0;

    printf("🎂 Enter student age: ");
    scanf("%d", &Student.age);
    clearInputBuffer();

    fwrite(&Student, sizeof(Student), 1, file);
    printf("\n✅ Success! Student '%s' has been registered. 🎉🎉\n", Student.name);
    printf("📁 Saved to file: %s\n", FILENAME);
    printf("-------------------------------------------------\n");

    fclose(file);
}

void listStudents(){
    FILE *file = fopen(FILENAME, "rb");
    student Student;
    int count = 0;
    if(file == NULL){
        printf("🚫 Error: Could not open file for reading.\n");
        return;
    }

    printf("All Students\n");
    printf("%-5s %-20s %-30s %-5s \n", "ID", "Name", "Email", "Age");
    printf("--------------------------------------------------------------");
    

    while (fread(&Student, sizeof(student), 1, file)) {
        printf("\n %-5d %-20s %-30s %-5d\n", 
               Student.id, Student.name, Student.email, Student.age);
        count++;
    }
    
    if(count == 0){
    	printf("No students found. \n");
	} else{
		printf("Total students: %d\n", count);
	}
	
	fclose(file);
}

void updateStudent(){
    int id;
    printf("Enter student id:");
    scanf("%d", &id);

    
}




int main() {
    printf("📚 ============================================= 📚\n");
    printf("📘 Student Registration System - C Edition! 📘\n");
    printf("📚 ============================================= 📚\n\n");
    
    displayMenu();
  
    printf("\n\n👋 Thank you for using the system. Have a great day!\n");
    return 0;
}
