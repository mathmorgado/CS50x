SELECT DISTINCT name
FROM people
JOIN stars
  ON people.id = stars.person_id
JOIN movies
  ON stars.movie_id = movies.id
WHERE movies.id IN (
        SELECT movie_id
        FROM stars
        JOIN people
         ON stars.person_id = people.id
        WHERE people.id = (
            SELECT id
            FROM people
            WHERE name = "Kevin Bacon" AND birth = 1958
        ))
AND name != "Kevin Bacon";