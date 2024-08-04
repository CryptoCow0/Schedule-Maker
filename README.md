# Schedule-Maker
Given a list of users and certain criteria's, this program creates a schedule for work
# AppleWood Athletic Club Schedule Maker

## Problem Description

The AppleWood Athletic Club schedule maker is a tailored scheduling tool designed for a small pool business. Due to the nature of the business, many responsibilities fall on the lifeguards. This tool generates a weekly schedule that meets all operational requirements for the pool at AppleWood Athletic Club. It is intended for use by knowledgeable users who understand the hierarchy and staffing needs of the pool.

## Program Documentation

The program operates by requesting input from the user regarding the number of staff needed and their respective levels. It then uses an algorithm to create a viable schedule. The process involves:

1. **User Input**: The user inputs the number of staff members and their levels.
2. **Algorithm**: An algorithm is employed to determine if a feasible schedule can be created and how it would function each day.
3. **Staff Selection**: Staff members are randomly selected from a vector based on the input criteria. A minimum of eight staff members are required.
4. **Validation**: The program checks if the selected staff can handle opening and closing jobs based on their management levels.
5. **Output**: The program generates a text file with the schedule. Although a graphical user interface (GUI) was considered, it was not implemented due to time constraints. Additionally, the current algorithm does not handle cases such as staff calling in sick or needing swaps, which would require more sophisticated logic.

Future improvements could include:
- Developing a GUI for better usability.
- Implementing a more complex algorithm to handle dynamic scheduling changes.
- Conducting extensive testing to cover edge cases and ensure robustness.

## List Data Structure

The primary data structure used is vectors, as they provide reliability and ease of use for this application. This choice allowed focus on developing a functional algorithm without concerns about data structure limitations.

## Tests

### Test One: Schedule Generation

- **Input**:
  - Staff Amount: 8
  - Names and Levels:
    - Miguel (2)
    - Kellen (2)
    - Clara (3)
    - Ava (3)
    - Judy (3)
    - Darain (1)
    - Sabrina (3)
    - Kate (1)
- **Expected Result**: A valid schedule should be generated as the required management levels are met.
- **Result**: A randomized schedule was successfully created, allowing for varied staff interactions.

### Test Two: Staff Amount Validation

- **Input**: Number of staff
- **Validation**: Ensures that the number of staff is at least 8.
- **Code Example**:
  ```cpp
  while (NumOfStaff < 8) {
      cout << "The minimum amount of staff is 8, not " << NumOfStaff << ". Try again: ";
      cin >> NumOfStaff;
  }


  ### Test Three: Staff Level Validation

- **Input**: Staff level
- **Validation**: Ensures the staff level is either 1, 2, or 3.
- **Code Example**:
    ```cpp
    while (staffLevel != 1 && staffLevel != 2 && staffLevel != 3) {
        cout << "Input 1, 2, or 3. Current input: " << staffLevel << endl;
        cout << "Input: ";
        std::cin >> staffLevel;
    }
    StaffLevelList.push_back(staffLevel);
    staffLevel = 0;
    ```
- **Expected Result**: The program prompts for valid input if an incorrect staff level is provided.

### Test Four: Insufficient Management Levels

- **Scenario**: All staff have management level 1.
- **Result**: The system generates a temporary text file indicating insufficient management levels to create a valid schedule.

### Test Five: Handling Negative Numbers

- **Scenario**: Negative numbers for staff levels.
- **Code Example**:
    ```cpp
    std::cin >> staffLevel;
    staffLevel = abs(staffLevel);
    ```

### Test Six: Schedule Editing

- **Scenario**: Editing the schedule by removing a staff member (e.g., Sabrina).
- **Expected Result**: The schedule is updated to reflect the removal of the staff member, and adjustments are made accordingly.
- **Actual Result**: The firing system correctly adjusts the schedule, ensuring coverage with minimal disruption.

