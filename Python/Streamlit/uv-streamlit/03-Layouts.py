import streamlit as st

st.set_page_config(
    page_title="Layouts",
    page_icon="😁"
)

st.title("Layouts")


# columns
col1, col2 = st.columns(2)

with col1:
    st.header("Iron Man / Tony Stark")
    st.image("https://i.redd.it/initium-roy-tower-concept-2-glasses-v0-ujcx8fank9q91.jpg?width=1440&format=pjpg&auto=webp&s=cd190c99fa1240a20b82a5e22de3b0ce78d3354f", width=200)
    vote_tony = st.button("Vote Tony")

with col2:
    st.header("Captain America / Steve Rogers")
    st.image("https://i.pinimg.com/736x/be/8b/44/be8b448bd58891e74db240f95546864a.jpg", width=200)
    vote_steve = st.button("Vote Steve")

banners = {
    "tony": "https://i.pinimg.com/736x/0a/57/d7/0a57d74703bae635f5f55c743ff64e27.jpg",
    "steve": "https://i.pinimg.com/1200x/83/0b/40/830b40c089850d21d12913c06cb870e5.jpg"
}


# vertical space
st.space("medium")


# sidebar
st.sidebar.header("Voter Details")
name = st.sidebar.text_input("Enter your name", placeholder="Natasha Romanoff")
age = st.sidebar.number_input("Enter your age", min_value=1, value=32)


# vote showing
tag = "tony"
if vote_steve:
    tag = "steve"

st.header(f"*{name or 'Voter'}* supports Team {tag.title()}")
st.image(banners[tag])


teams = {
    "tony": [
        # "Iron Man",
        "War Machine",
        "Black Widow",
        "Black Panther",
        "Vision",
        "Spider-Man"
    ],
    "steve": [
        # "Captain America",
        "Winter Soldier",
        "Falcon",
        "Scarlet Witch",
        "Hawkeye",
        "Ant-Man"
    ]
}

# expander
with st.expander(f"Show {tag.title()} Team Members"):
    st.write(f"1. {name} (You)")
    i = 2
    for name in teams[tag]:
        st.write(f"{i}. {name}")
        i += 1
