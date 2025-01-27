SELECT DISTINCT name
FROM movies, people, stars
WHERE movies.id = stars.movie_id
AND stars.person_id = people.id
AND title IN(
    SELECT title
    FROM movies, people, stars
    WHERE movies.id = stars.movie_id
    AND stars.person_id = people.id
    AND name = 'Kevin Bacon'
    AND birth = '1958'
)
AND name != 'Kevin Bacon';
