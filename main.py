import speech_recognition as sr
import pyttsx3
import wikipediaapi

# Initialize the recognizer, text-to-speech engine, and Wikipedia API
recognizer = sr.Recognizer()
tts_engine = pyttsx3.init()
wiki_wiki = wikipediaapi.Wikipedia('en')

def speak(text):
    """Convert text to speech and speak it."""
    tts_engine.say(text)
    tts_engine.runAndWait()

def get_wikipedia_summary(query):
    """Fetch the summary from Wikipedia."""
    try:
        page = wiki_wiki.page(query)
        if page.exists():
            return page.summary[:500]  # Limit to first 500 characters
        else:
            return "Sorry, I couldn't find any information on that topic."
    except Exception as e:
        return f"An error occurred: {str(e)}"

def listen_to_user():
    """Capture audio input from the user and return the recognized text."""
    with sr.Microphone() as source:
        print("Listening...")
        recognizer.adjust_for_ambient_noise(source)  # Adjust for ambient noise
        audio = recognizer.listen(source)
        try:
            text = recognizer.recognize_google(audio)
            print(f"You said: {text}")
            return text
        except sr.UnknownValueError:
            return "Sorry, I didn't catch that."
        except sr.RequestError as e:
            return f"Sorry, there was a problem with the speech recognition service: {str(e)}"

def main():
    print("Say 'stop' to end.")
    while True:
        user_input = listen_to_user()
        if user_input.lower() == 'stop':
            speak("Goodbye!")
            break
        if user_input:
            summary = get_wikipedia_summary(user_input)
            speak(summary)

if __name__ == "__main__":
    main()
