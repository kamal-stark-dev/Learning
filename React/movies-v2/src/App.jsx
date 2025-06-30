import { useState } from "react";

const Card = ({ title, rating, isBadass, actors }) => {
  const [hasLiked, setHasLiked] = useState(false);

  return (
    <div
      style={{
        background: "#121212",
        padding: "24px",
        border: "2px solid white",
      }}
    >
      <h2>{title}</h2>
      <p>Rating: {rating} </p>
      <p>Badass: {isBadass ? "Yes" : "No"}</p>
      <p>Star Cast: {actors}</p>
      <button onClick={() => setHasLiked(!hasLiked)}>
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
