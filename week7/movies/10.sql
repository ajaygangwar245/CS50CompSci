SELECT DISTINCT name
FROM movies, people, ratings, directors
WHERE movies.id = directors.movie_id
AND directors.person_id = people.id
AND movies.id = ratings.movie_id
AND rating >= 9.0;
