1. Count the customer with grades above Bangalore's average

SELECT GRADE, COUNT (CUSTOMER_ID) FROM 
CUSTOMER GROUP BY GRADE 
HAVING GRADE > (SELECT AVG (GRADE) FROM 
CUSTOMER WHERE CITY='BANGALORE');

2. Find the name and numbers of all salesmen who had more than one customer. 

SELECT SALESMAN_ID,NAME 
FROM SALESMAN A 
WHERE 1 <(SELECT COUNT(*) FROM CUSTOMER 
WHERE SALESMAN_ID=A.SALESMAN_ID) 
OR 
SELECT S.SALESMAN_ID,NAME, FROM CUSTOMER 
C,SALESMAN S WHERE 
S.SALESMAN_ID=C.SALESMAN_ID GROUP BY 
C.SALESMAN_ID HAVING COUNT(*)>1

3. List all salesmen and indicate those who have and don’t have customers in 
their cities (Use UNIONoperation.) 

SELECT S.SALESMAN_ID,NAME,CUST_NAME,COMMISSION FROM SALESMAN 
S,CUSTOMER C 
WHERE S.CITY = C.CITY 
UNION 
SELECT SALESMAN_ID, NAME, 'NO MATCH',COMMISSION FROM SALESMAN 
WHERE NOT CITY = ANY (SELECT CITY
FROM CUSTOMER) ORDER BY 2 DESC;

4. List all salesmen and indicate those who have and don’t have customers in 
their cities (Use UNIONoperation.) 

CREATE VIEW VW_ELITSALESMAN AS 
SELECT B.ORD_DATE,A.SALESMAN_ID,A.NAME FROM SALESMAN A, ORDERS B 
WHERE A.SALESMAN_ID = B.SALESMAN_ID AND B.PURCHASE_AMT=(SELECT 
MAX(PURCHASE_AMT) FROM ORDERS C 
WHERE C.ORD_DATE = B.ORD_DATE);
SELECT * FROM VW_ELITSALESMAN

5. Demonstrate the DELETE operation by removing salesman with id 1000. All his orders 
must also be deleted. 
Use ON DELETE CASCADE at the end of foreign key definitions while creating child table 
orders and then execute the following: 

DELETE FROM SALESMAN WHERE SALESMAN_ID=101; 
