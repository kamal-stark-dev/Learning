import streamlit as st
import matplotlib.pyplot as plt

st.set_page_config(
    page_title="Graphs & Plots",
    page_icon="📊"
)

st.title("Graphs & Plots")

st.subheader("Plot")

x = [0, 1, 2, 3, 4]
y = [0, 1, 4, 9, 16]

fig, ax = plt.subplots()
ax.plot(x, y)
ax.set_title("Plot")

st.pyplot(fig, width=500)
