import { useState, useEffect } from "react";

const Card = ({ title, rating, isBadass, actors }) => {
  const [count, setCount] = useState(0);
  const [hasLiked, setHasLiked] = useState(false);

  useEffect(() => {
    console.log(`${title} has been: ${hasLiked ? "Liked" : "Disliked"}`);
  }, [hasLiked]);

  useEffect(() => {
    console.log("Card Rendered!");
  }, []); // will only render when the component is first made

  return (
    <div
      className="card"
      onClick={() => setCount((prevState) => prevState + 1)}
    >
      <h2>
        {title} - {count}
      </h2>
      <p>Rating: {rating} </p>
      <p>Badass: {isBadass ? "Yes" : "No"}</p>
      <p>Star Cast: {actors}</p>
      <button onClick={() => setHasLiked((prevHasLiked) => !prevHasLiked)}>
        {hasLiked ? "❤️" : "🤍"}
      </button>
    </div>
  );
};

const App = () => {
  return (
    <>
      <h2 style={{ fontSize: "32px", marginBottom: "48px" }}>
        Functional Arrow Component
      </h2>
      <div className="card-container">
        <Card
          title="Kesari: Chapter 2"
          rating={4.1}
          isBadass={false}
          actors={["Akshay Kumar", "R. Madhavan", "Ananya Pandey"]}
        ></Card>
        <Card
          title="KGF Chapter 2"
          rating={4.8}
          isBadass={true}
          actors={["Yash", "Sanjay Dutt", "Raveena Tandon", "Srinidhi Shetty"]}
        ></Card>
        <Card
          title="Bajrangi Bhaijaan"
          rating={4.6}
          isBadass={false}
          actors={["Salman Khan", "Kareena Kapoor", "Nawazuddin Siddiqui"]}
        ></Card>
      </div>
    </>
  );
};
export default App;
