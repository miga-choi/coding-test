-- /* Write your PL/SQL query statement below */
SELECT person.firstName, person.lastName, address.city, address.state
FROM Person person, Address address 
WHERE person.personId = address.personId (+);


-- Best Solution
-- Using conventional method by making equal both the attributes of the table to join them
select p.firstName, p.lastName, a.city, a.state 
from Person p LEFT JOIN Address a on p.personId = a.personId

-- Use USING() function
select p.firstName, p.lastName, a.city, a.state 
from Person p LEFT JOIN Address a USING(personId) 