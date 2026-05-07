import streamlit as st
import requests

st.set_page_config(page_title="Currency Convertor", page_icon=":money_with_wings:")

st.title("Live Currency Converter")

base_currency = st.selectbox("Select Currency:", ["USD", "INR", "EUR", "GBP", "JPY"])
amount = st.number_input(f"Enter the amount in {base_currency}", min_value=1)
target_currency = st.selectbox("Convert to:", ["USD", "INR", "EUR", "GBP", "JPY"])

if st.button("Convert"):
    url = f"https://api.exchangerate-api.com/v4/latest/{base_currency}"
    response = requests.get(url)

    if response.status_code != 200:
        st.error("Failed to fetch conversion rate.")
        st.stop()

    data = response.json()
    rate = data["rates"][target_currency]
    converted = rate * amount
    st.success(f"{amount} INR = {converted: .2f} {target_currency}")
    st.balloons()
