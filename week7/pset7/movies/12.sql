SELECT DISTINCT title
FROM movies
JOIN stars
  ON movies.id = stars.movie_id
JOIN people
  ON stars.person_id = people.id
WHERE people.id IN (
        SELECT id
        FROM people
        WHERE name = "Bradley Cooper" OR name = "Jennifer Lawrence")
GROUP BY movies.id
HAVING COUNT(DISTINCT name) = 2;