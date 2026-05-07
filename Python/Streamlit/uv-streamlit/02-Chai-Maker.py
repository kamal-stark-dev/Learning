from datetime import datetime, date
import streamlit as st

# ---------------- PAGE CONFIG ----------------
st.set_page_config(
    page_title="Chai Maker App",
    page_icon="☕",
    layout="centered"
)

# ---------------- TITLE ----------------
st.title("☕ Chai Maker App")
st.markdown("Customize your perfect cup of chai!")

st.divider()

# ---------------- FORM ----------------
with st.form("chai_form"):

    st.subheader("☕ Chai Form")

    # Name
    name = st.text_input(
        "Enter your name",
        placeholder="Tony Stark"
    )

    # Tea Base
    tea_base = st.radio(
        "Choose your chai base:",
        [
            "🥛 Milk",
            "💧 Water",
            "🍺 Beer",
            "🌰 Almond Milk"
        ]
    )

    # Flavour
    flavour = st.selectbox(
        "Choose flavour:",
        [
            "🫚 Aadrak",
            "🌿 Tulsi",
            "✨ Kesar",
            "🟢 Elaichi"
        ]
    )

    # Masala
    add_masala = st.checkbox("Add Masala")

    # Sugar
    sugar = st.slider(
        "Sugar (teaspoons)",
        min_value=0,
        max_value=5,
        value=2
    )

    # Cups
    cups = st.number_input(
        "How many cups?",
        min_value=1,
        max_value=8,
        step=1
    )

    # DOB
    dob = st.date_input(
        "Date of Birth",
        min_value=date(1900, 1, 1),
        max_value=date.today(),
        value=None,
        format="DD/MM/YYYY"
    )

    # Submit Button
    submit = st.form_submit_button("☕ Make My Chai")


# ---------------- OUTPUT ----------------
if submit:

    if not name:
        st.warning("Please enter your name.")
        st.stop()

    st.success("Your chai is being brewed... ☕")

    # Accurate age calculation
    if dob:
        today = date.today()

        age = today.year - dob.year - (
            (today.month, today.day) < (dob.month, dob.day)
        )

        st.info(f"🎂 You are {age} years old.")

    # Chai Summary
    st.subheader("🧾 Chai Summary")

    st.write(f"👤 **Customer:** {name}")
    st.write(f"☕ **Base:** {tea_base}")
    st.write(f"🌿 **Flavour:** {flavour}")
    st.write(f"🍬 **Sugar:** {sugar} teaspoon(s)")
    st.write(f"🥤 **Cups:** {cups}")

    if add_masala:
        st.write("🔥 Extra Masala added")
    else:
        st.write("❌ No Masala")

    # Fun message
    st.balloons()

    st.markdown(
        f"""
        ### ✅ Order Confirmed

        Hey **{name}**, your **{cups}** cup(s) of **{flavour} chai**
        with **{sugar} spoon(s) of sugar**
        is on the way! ☕
        """
    )