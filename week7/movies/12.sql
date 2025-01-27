SELECT title
FROM movies, people, stars
WHERE movies.id = stars.movie_id
AND stars.person_id = people.id
AND name = 'Bradley Cooper'
AND title IN (
    SELECT title
    FROM movies, people, stars
    WHERE movies.id = stars.movie_id
    AND stars.person_id = people.id
    AND name = 'Jennifer Lawrence'
);

