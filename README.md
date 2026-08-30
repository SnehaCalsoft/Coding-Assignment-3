# Coding-Assignment-3

This repository contains three coding assignments implemented using **C++ and Python**.

The assignments demonstrate:

* Object-Oriented Programming (OOP)
* File handling
* JSON parsing
* Log file parsing
* Exception handling
* Operating-system-level commands
* Python modules and inheritance
* Efficient processing of large files

---

## Assignments

| Assignment            | Language | Main Concepts                                         |
| --------------------- | -------- | ----------------------------------------------------- |
| Get Hardware Info     | Python   | OOP, inheritance, abstract classes, OS commands, JSON |
| Filter Inventory Data | C++      | OOP, JSON parsing, filtering, exception handling      |
| Log File Parsing      | C++      | File handling, parsing, filtering, exception handling |

---

# 1. Get Hardware Info

## Problem Statement

Write a program to display real-time hardware information of the system using an Object-Oriented Programming approach and Python package/module concepts.

The program retrieves information about:

* Hostname
* Memory
* CPU
* IP address
* Disk size

The program automatically determines whether it is running on **Windows or Linux** and uses the appropriate implementation.

## OOP Design

The program uses a parent class:

```text
HostInfo
   |
   +---- LinuxHost
   |
   +---- WindowsHost
```

### `HostInfo`

The parent class contains the common attributes:

```text
hostname
memory
cpu
ip
disk_size
```

It also defines:

```text
get_hardware_info()
display_hardware_info()
```

`get_hardware_info()` is an abstract method and must be implemented by the child classes.

### `LinuxHost`

The Linux-specific implementation obtains hardware information using Linux OS-level commands.

### `WindowsHost`

The Windows-specific implementation obtains hardware information using Windows commands such as `systeminfo` and other appropriate system commands.

## Features

* Automatically detects the operating system.
* Creates either a `LinuxHost` or `WindowsHost` object.
* Retrieves hardware information from the current machine.
* Uses inheritance to avoid duplicating common functionality.
* Displays the collected information in JSON format.

## Technologies Used

* Python
* Object-Oriented Programming
* Abstract classes
* Inheritance
* Python modules/packages
* OS-level commands
* JSON

## Running the Program

From the hardware information directory:

```bash
python main.py
```

The program detects the operating system and runs the appropriate class.

---

# 2. Filter Inventory Data

## Problem Statement

Given a JSON file containing inventory information for multiple systems, filter the inventory based on:

* Maximum Memory
* Maximum CPU
* Linux systems
* Windows systems

The program accepts a filter criterion and displays the corresponding inventory information.

## Input

The inventory is stored in a JSON file.

Example:

```json
{
    "inventory": {
        "10.217.09.18": {
            "ip": "10.217.09.18",
            "os": "Windows",
            "memory": "2GB",
            "cpu": "3.1Ghz",
            "disk": "100GB"
        }
    }
}
```

## Filter Criteria

The following criteria are supported:

```text
Memory
CPU
Linux
Windows
```

### Memory

If the filter criterion is:

```text
Memory
```

the program finds and displays the system with the maximum memory.

For the sample data, this would be:

```text
10.217.09.24
Memory: 16GB
```

### CPU

If the filter criterion is:

```text
CPU
```

the program finds and displays the system with the maximum CPU value.

For the sample data:

```text
10.217.09.19
CPU: 3.8Ghz
```

### Linux

If the filter criterion is:

```text
Linux
```

all systems whose OS is Linux are displayed.

### Windows

If the filter criterion is:

```text
Windows
```

all systems whose OS is Windows are displayed.

## Exception Handling

The program handles invalid input conditions.

### Missing Filter Criterion

An exception is raised if no filter criterion is provided.

### Invalid Filter Criterion

An exception is raised if the supplied criterion is not one of:

```text
Memory
CPU
Linux
Windows
```

## OOP Design

The implementation uses C++ classes to separate:

* JSON/inventory handling
* Filtering logic
* Input validation
* Output

The filtering logic is designed to avoid unnecessary sorting when finding the maximum Memory or CPU.

For example, finding the maximum CPU can be done in a single pass:

```text
Read item
   ↓
Convert CPU value
   ↓
Compare with current maximum
   ↓
Update maximum if required
```

This avoids sorting the complete inventory when only the maximum value is required.

## Technologies Used

* C++
* Object-Oriented Programming
* JSON
* File handling
* Exception handling
* STL

## Running the Program

Compile the program using the appropriate C++ compiler and run it with the inventory JSON file and filter criterion according to the implementation.

Example:

```bash
./inventory <filter>
```

Example filters:

```text
Memory
CPU
Linux
Windows
```

---

# 3. Log File Parsing

## Problem Statement

Given a log file, parse the file based on log types and display the most recent matching log entries.

The supported log types are:

```text
error
warning
info
debug
```

The program accepts:

1. File path
2. Number of logs to display — optional
3. Log types to display — optional

## Input Parameters

### 1. File Path

The path of the log file is required.

Example:

```text
Q1_Log_19_10_17_11_42_01.log
```

If the file path is invalid, the program raises an exception.

### 2. Number of Logs

The number of matching logs to display is optional.

Default:

```text
10
```

For example:

```text
100
```

means the program should find the most recent 100 matching log entries.

### 3. Log Types

The log types are optional and can contain one or multiple types separated by commas.

Default:

```text
error
```

Examples:

```text
error
```

or:

```text
error,warning
```

or:

```text
error,warning,info,debug
```

## Log Format

Each log entry begins with one of the supported log types.

For example:

```text
[INFO] 2019-10-17 11:46:52 root() : Start parsing the plugin vrops

[DEBUG] 2019-10-17 11:46:52 urllib3.connectionpool() : Starting new HTTPS connection

[ERROR] 2019-10-17 11:41:39 util.rest_client() : Unable to initiate rest call
```

The program identifies the log type and checks whether it matches the requested filter.

## Most Recent Logs

The requirement is to display the **most recently added matching logs**.

Therefore, the file is processed starting from the end.

Conceptually:

```text
End of file
     ↓
Read latest log
     ↓
Check log type
     ↓
Does it match?
   /       \
 Yes       No
  ↓         ↓
Store     Continue
  ↓
Required number reached?
  ↓
 Stop
```

For example, if the user requests:

```text
Number of logs = 10
Type = error
```

the program starts from the end of the file and continues backwards until it finds 10 `ERROR` entries.

This avoids processing the entire file when the required number of recent matching entries has already been found.

## Validation

The program raises an exception when:

* The file path is invalid.
* An invalid log type is supplied.

Valid log types are:

```text
error
warning
info
debug
```

## Default Values

If optional parameters are not provided:

```text
Number of logs = 10
Log type = error
```

## Technologies Used

* C++
* Object-Oriented Programming
* File handling
* String parsing
* Exception handling
* STL

# Concepts Demonstrated

## Object-Oriented Programming

The assignments make use of:

* Classes
* Objects
* Encapsulation
* Inheritance
* Abstraction
* Polymorphism

## File Handling

The C++ assignments work with external files such as:

```text
JSON files
LOG files
```

The Python assignment interacts with the operating system to retrieve real-time information.

## Exception Handling

Invalid inputs and file-related errors are handled using exceptions rather than allowing the program to fail silently.

## JSON

The inventory assignment reads structured inventory data from a JSON file and processes the information programmatically.

## Efficient Processing

The implementations are designed with large inputs in mind.

For inventory:

* Maximum Memory/CPU can be found without sorting the entire dataset.

For log parsing:

* The file is processed from the end so that recent matching logs can be found without unnecessarily processing older entries.

---

# Summary

This project consists of three system-oriented programming assignments:

### Get Hardware Info — Python

Retrieves real-time hardware information using OS-level commands and demonstrates inheritance, abstraction, and Python modules.

### Filter Inventory Data — C++

Reads inventory information from JSON and filters systems based on maximum Memory, maximum CPU, or operating system.

### Log File Parsing — C++

Reads and filters log files based on log type and displays the most recent matching entries while supporting optional parameters and exception handling.

Together, these assignments demonstrate practical usage of **OOP, file handling, JSON processing, system commands, parsing, exception handling, and efficient data processing** in both Python and C++.
