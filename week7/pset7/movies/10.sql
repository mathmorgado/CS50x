SELECT DISTINCT name
     FROM people
    JOIN directors
      ON people.id = directors.person_id
      WHERE directors.movie_id IN (
        SELECT DISTINCT movie_id
         FROM ratings
        WHERE rating >= 9);