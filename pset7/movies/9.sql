SELECT DISTINCT people.name
FROM stars, movies
INNER JOIN people ON stars.person_id = people.id AND stars.movie_id = movies.id
WHERE year = 2004
ORDER BY birth ASC;

