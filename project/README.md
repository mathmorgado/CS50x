<h1 align="center">FINANCERS</h1>

### Video Demo:  https://www.youtube.com/watch?v=pPigWn5juXU
#### Description: _Develop greater financial awareness by recording and managing your spending!_

---
_Main technologies used_:
- *Python*
- *Flask*
- *HTML*
- *CSS*
- *SQL*

_Features_:
- Registration, login and logout logic
- Session logic (cookies)
- Categorization of finances as: Receipts, accounts, debts, leisure and others.
- Description of each expense Ex: Food - $100...
- Delete function
---
## About

With the aim of promoting financial awareness, the program seeks to record users' expenses and income. In this way, it aims to empower individuals by providing a comprehensive view of their financial landscape through the categorization of data into five distinct tables: Income, Bills, Debts, Leisure, and Other.

The primary goal of this separation is to offer users greater visibility into the dynamics of their financial transactions. By delineating expenses into various categories, individuals can gain valuable insights into the patterns and areas where a significant portion of their income is allocated. This approach allows users to make smarter decisions, promoting a more strategic approach to financial planning and management.

This idea arose from a need when I started my financial life: managing my personal finances. What were my main expenses? What was the total expenditure on bills and fees? How much did I spend on unforeseen expenses, such as buying a refreshing drink on the way to work or a quick snack to satisfy hunger while walking down the street?

These questions lingering in my mind planted the seed of an idea that would come to fruition in the future. However, what fueled the fervor for this idea was when I asked my father about his expenses, how much he had left to spend, and he couldn't answer. It was then that I decided to pursue this project to plan an intelligent distribution, not only of my finances but also of my father's and anyone else who needed this tool!

I started by using the files from Finance, from problem set nine, as a base and deleted the routes/functions "buy, sell, history, and quote" since they would no longer be necessary. I also erased all the logic for login, registration, and logout to start everything from scratch. Additionally, I made some adaptations to the code of the "USD" function for my native currency "BRL" and changed the color palette of the program to gray and white, also altering the entire program's design.

With that, I began developing the system, first creating the registration page, consisting of a Navbar with two items: the initial registration page and the login page. Both pages have a central area with fields, where in registration: username, password, and confirmation; and in login: username and password. Both have a button and a redirection to the other page, in case the user is already registered or needs to register!

After successfully logging in, the user is seamlessly directed to the program's main page. This page is designed to be straightforward, featuring four key fields: Income, Expenses, Balance, and a form.

The Income, Expenses, and Balance fields provide essential information clearly, giving the user an immediate overview of their financial situation. The form is where users can input details for each expense, such as category and amount.

As the user adds expenses in the form, tables begin to appear on the page, reflecting the entered information. These tables are organized by category, offering a simple visual representation of expenses over time. This makes it easy for the user to understand how money is being spent in different areas.

Now, the most engaging part of the development was the entire system's logic, especially the interaction between Python and the SQL database, where I had to store the data for each table and correctly implement the information in their respective tables. My progress in programming with Python became evident during this project, as I found myself not just thinking about the Python language itself but rather about the problem, instinctively translating the solution into Python!

Within all the logic I developed in the project, I highlight three parts: the 'base_tables' variable, the 'calculate_totals' function, and the 'delete' route.

Creating a list of dictionaries where the values are all the items inside the table corresponding to the key of the 'base_tables' variable was a 'smart' solution to compress all the information I needed into a single place, linking each piece of information to its respective table!

As for the 'calculate_totals' function, it's the most well-executed application of the 'Don't repeat code!' idea I've ever done. First, I developed logic to get the sum of all values, considering only the entry values and using both to calculate the exit value. Then, I encapsulated everything into a function that returns three variables: entries, exits, and total!

Now, the 'delete' route was the cleverest move I've had. First, I created the logic to delete the item, but I didn't know how to make the button click execute this action. That's when I thought about what I did with the tables' own form, where clicking the button sent me through the index route. I thought about applying this but sending it to the delete route and then redirecting to the index!

My biggest difficulty throughout the project was definitely the front-end! I have very little knowledge in this area and it was certainly the part that I struggled the most to develop, it took me a long time in this part and even though I tried hard, the result was not as expected. However, as difficult as it was, I managed to understand many css and html concepts thanks to all this difficulty.

Reaching the end of this project, I was able to understand which technologies I am more comfortable with and which ones pose more challenges. My plan now is to delve deeper into Python, and concurrently, work on developing the areas where I encountered more difficulties.

No matter how simple the project is, it's an important project for me, and I plan to continue working on and developing it even after the completion of the CS50x course. So be prepared for version 2.0, 3.0, and beyond!

Thank you all for your time, have a great day, and "This is CS50"! 🐣
