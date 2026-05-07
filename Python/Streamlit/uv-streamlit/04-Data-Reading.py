import streamlit as st
import pandas as pd

st.set_page_config(
    page_title="Reading Data",
    page_icon="📄"
)

st.title("📄 CSV Loading")

file = st.file_uploader("Upload your CSV file", type=["csv"])

if file:
    df = pd.read_csv(file)
    st.subheader("Data Preview")
    st.dataframe(df)

    st.subheader("Summary Stats")
    st.write(df.describe())