SELECT * FROM shows ORDER BY title ASC;

UPDATE shows SET title = "Adventure Time" WHERE title LIKE "adventure t%";
UPDATE shows SET title = "Arrow" WHERE title LIKE "arrow%";
UPDATE shows SET title = "Criminal Minds" WHERE title LIKE "criminal minds%";
UPDATE shows SET title = "Family Guy" WHERE title LIKE "family guy%";
UPDATE shows SET title = "Billions" WHERE title LIKE "billions%";
UPDATE shows SET title = "Community" WHERE title LIKE "community%";
UPDATE shows SET title = "Friends" WHERE title LIKE "friends%";
UPDATE shows SET title = "Sherlock Holmes" WHERE title LIKE "sherlock%";
UPDATE shows SET title = "Squid Game" WHERE title LIKE "squid g%";
UPDATE shows SET title = "The Untamed" WHERE title LIKE "the untam%";
UPDATE shows SET title = "The Barchelorette" WHERE title LIKE "the bachelore%";

SELECT * FROM shows ORDER BY title ASC;