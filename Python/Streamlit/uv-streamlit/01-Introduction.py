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

# markdown
st.divider()

st.markdown("# -> Markdown")
st.markdown("> This is a blockquote.")
st.markdown(":streamlit: **Streamlit** is cool. :sunglasses:")
st.markdown("### Material Icons: :material/search: :material/home: :material/menu: :material/close: :material/settings: :material/favorite: etc.")
st.markdown("Latex: $$\sum_0^n{f(n)}$$ or $$a^2 + b^2 = c^2$$")

st.markdown("Hello, :green-background[World!]")