import streamlit as st

st.title("Hello Streamlit App")
st.text("Welcome to your first strealit interactive app.")
st.write("Choose your favorite movie.")

movie = st.selectbox(
    "Choose here",
    [
        "Select",
        "Fight Club",
        "Interstellar",
        "Dhurandhar: The Revenge",
        "KGF: Chapter 2",
        "Iron Man"
    ]
)

choice_type = "solid"
if movie == "Interstellar":
    choice_type = "brilliant"
if movie != "Select":
    st.write(f"You choose {movie}, that's a {choice_type} choice.")
    st.success("I hope you get the basic idea.")
