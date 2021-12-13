SELECT people.name
FROM stars, movies
INNER JOIN people ON stars.person_id = people.id AND stars.movie_id = movies.id
WHERE title ='Toy Story';

