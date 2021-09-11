# EMPLOYEE PRESENCE MONITORING SYSTEM  
## Two modes:-  
### 1.Employee mode  
    1.Mark attendance  
    2.Move out  
    3.Move in  
    4.Go to main menu  
    5.Exit  

### 2.Admin mode (Default password is admin)  
    1.Number of employees came today  
    2.Check particular employee's attendance of today  
    3.Number of times entrance of particular employee  
    4.Employee that moves out most number of times  
    5.Name of the employees out for particular time period  
    6.Employees who came within range of ids and how often they entered  
    7.Change admin password  
    8.Add employee  
    9.Get all employees details  
    10.Go to main menu  
    11.Exit

#### Note :-  
    when first time program is run ,two binary files "credential.dat" and "employees_details.dat" are created.  
    "credential.dat" stores admin's password with default password 'admin' and "employees_details.bat" contains employees' data.Employee Id(emp_id) starts from 1 and when new employee is added by admin, id is incremented by 1 and is assigned to new employee automatically.  
    Admin can change password and the new password is written to  "credential.dat".If in case this file is deleted,then next time the program is run, new "credential.dat" is created and it contains 'admin' as default password.  
    If "employees_details.dat" is deleted all employees' data is deleted, then admin has to again add all data.
