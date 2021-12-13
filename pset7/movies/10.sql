SELECT DISTINCT people.name
FROM directors, ratings, movies
INNER JOIN people ON ratings.movie_id = movies.id AND people.id = directors.person_id AND directors.movie_id = movies.id
WHERE rating >= 9.0;
