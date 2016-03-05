-- The Employee table holds all employees. Every employee has an Id, and there is also a column for 
-- the department Id.

-- +----+-------+--------+--------------+
-- | Id | Name  | Salary | DepartmentId |
-- +----+-------+--------+--------------+
-- | 1  | Joe   | 70000  | 1            |
-- | 2  | Henry | 80000  | 2            |
-- | 3  | Sam   | 60000  | 2            |
-- | 4  | Max   | 90000  | 1            |
-- | 5  | Janet | 69000  | 1            |
-- | 6  | Randy | 85000  | 1            |
-- +----+-------+--------+--------------+
-- The Department table holds all departments of the company.

-- +----+----------+
-- | Id | Name     |
-- +----+----------+
-- | 1  | IT       |
-- | 2  | Sales    |
-- +----+----------+
-- Write a SQL query to find employees who earn the top three salaries in each of the department. For the 
-- above tables, your SQL query should return the following rows.

-- +------------+----------+--------+
-- | Department | Employee | Salary |
-- +------------+----------+--------+
-- | IT         | Max      | 90000  |
-- | IT         | Randy    | 85000  |
-- | IT         | Joe      | 70000  |
-- | Sales      | Henry    | 80000  |
-- | Sales      | Sam      | 60000  |
-- +------------+----------+--------+

SELECT Department.Name AS Department, Tmp.Name AS Employee, Tmp.Salary AS Salary
FROM (
    SELECT Name, Salary, DepartmentId, 
    	@rank := IF(DepartmentId=@did, IF(Salary<>@sal, @rank + 1, @rank), 1) AS RowNum, 
    	@did:=DepartmentId, @sal:=Salary
    FROM (
        SELECT Name, Salary, DepartmentId
        FROM Employee
        ORDER BY DepartmentId, Salary desc
    ) AS Ordered, (SELECT @rank:=0, @did:=0, @sal:=0) AS Variables
) AS Tmp
JOIN Department
ON Department.Id = Tmp.DepartmentId
WHERE Tmp.RowNum <= 3;
