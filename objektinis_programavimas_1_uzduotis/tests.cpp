#include <stdio.h>
#define CATCH_CONFIG_MAIN
#include "Studentas.h"
#include "Header.h"
#include "catch.hpp"


// Test case for the constructor with parameters
TEST_CASE("Studentas constructor initializes correctly", "[Studentas]") {
    string vardas = "Jonas";
    string pavarde = "Jonaitis";
    vector<int> namu_darbai = {8, 9, 10};
    int egzaminas = 9;

    // Create a Studentas object
    Studentas student(vardas, pavarde, namu_darbai, egzaminas);

    // Verify that the data members are initialized correctly
    REQUIRE(student.getVardas() == vardas);
    REQUIRE(student.getPavarde() == pavarde);
    REQUIRE(student.getNamuDarbai() == namu_darbai);
    REQUIRE(student.getEgzaminas() == egzaminas);
}

// Test case for the assignment operator
TEST_CASE("Testing the assignment operator of Studentas class", "[operator=]") {

    // Creating a Studentas object
    vector<int> namu_darbai = {8, 9, 7, 6};
    Studentas student1("Jonas", "Jonaitis", namu_darbai, 80);

    // Test Case 1: Self-assignment
    student1 = student1;  // Assign object to itself

    // Assert that the values of student1 haven't changed after self-assignment
    REQUIRE(student1.getVardas() == "Jonas");
    REQUIRE(student1.getPavarde() == "Jonaitis");
    REQUIRE(student1.getNamuDarbai() == namu_darbai);
    REQUIRE(student1.getEgzaminas() == 80);

    // Test Case 2: Assigning one object to another
    vector<int> namu_darbai2 = {10, 9, 8, 7};
    Studentas student2("Petras", "Petraitis", namu_darbai2, 90);
    
    // Perform the assignment
    student1 = student2;

    // Check if student1's data was copied correctly from student2
    REQUIRE(student1.getVardas() == "Petras");
    REQUIRE(student1.getPavarde() == "Petraitis");
    REQUIRE(student1.getNamuDarbai() == namu_darbai2);
    REQUIRE(student1.getEgzaminas() == 90);
}
