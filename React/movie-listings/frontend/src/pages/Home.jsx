import MovieCard from "../components/MovieCard";
import { useState } from "react"; // hook

function Home() {
  const [searchQuery, setSearchQuery] = useState("");

  const movies = [
    { id: 1, title: "John Wick", release_date: "2020" },
    { id: 2, title: "Avengers: Endgame", release_date: "2019" },
    { id: 3, title: "Inception", release_date: "2010" },
    { id: 4, title: "The Dark Knight", release_date: "2008" },
    { id: 5, title: "Spider-Man: No Way Home", release_date: "2021" },
    { id: 6, title: "Black Panther", release_date: "2018" },
    { id: 7, title: "Interstellar", release_date: "2014" },
    { id: 8, title: "3 Idiots", release_date: "2009" },
    { id: 9, title: "Dangal", release_date: "2016" },
    { id: 10, title: "Iron Man", release_date: "2008" },
  ];

  const handleSearch = () => {};

  return (
    <div className="home">
      <form onSubmit={handleSearch} className="search-form">
        <input
          type="text"
          placeholder="Search for movies..."
          className="search-input"
          value={searchQuery}
        />
        <button type="submit" className="search-button">
          Search
        </button>
      </form>
      <div className="movies-grid">
        {movies.map((movie) => (
          <MovieCard movie={movie} key={movie.id} />
        ))}
      </div>
    </div>
  );
}

export default Home;

/*
States - State is something where once it's updated, the component will change and re-render itself to show the new state.
*/
