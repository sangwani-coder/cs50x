SELECT movies.title
FROM stars, ratings, people
INNER JOIN movies ON movies.id = stars.movie_id AND stars.person_id = people.id AND stars.movie_id = movies.id AND ratings.movie_id = movies.id
WHERE name = 'Chadwick Boseman'
ORDER BY rating DESC
LIMIT 5;