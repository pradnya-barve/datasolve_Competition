# COMPETITION NAME : DataSolve 2022

## Steps to setup project

clone the repository
```
git clone https://github.com/pradnya-barve/datasolve_Competition.git
```

create virtual environment by using virtualenv
```
pip install virtualenv
virtualenv env
```

activate env
```
cd env/Scripts
.\activate
```
install required libraries
```
    pip install -r requirements.txt

```

create a dataset folder.dowload and store the dataset in that folder.
dataset link
```
https://www.kaggle.com/competitions/datasolve-india/data
```

# NLP
### steps in NLP

```
Tokenization
Stemming
Lemmatization
Part-of-speech (POS) tagging
Named entity recognition
Chunking

```
#### 1) Tokenization
We break down the text into tokens. Check the example below to see how this is done.
Text: The cat sat on the bed. Tokens: The, cat, sat, on, the, bed

#### 2) Stemming
We remove the prefixes and suffixes to obtain the root word. Check the example below to see how it’s done.
List of words: Affection, Affects, Affecting, Affected, Affecting
Root word: Affect

#### 3) Lemmatization
We group together different inflected forms of a word into a base word called lemma. Check the example below how it’s done.
List of words: going, gone, went
Lemma: go

#### 4) Part-of-speech (POS) tagging
We identify the parts of speech for different tokens. Check the example below to see how it’s done.

Sentence: The dog killed the bat.
Parts of speech: Definite article, noun, verb, definite article, noun.

#### 5) Named entity recognition
We classify named entities mentioned in the text into categories such as "People", "Locations","Organizations," and so on. Check the example below to see how it’s done.

Text: Google CEO Sundar Pichai resides in New York.
Named entity recognition:
Google — Organization
Sundar Pichai — Person
New York — Location

#### 6) Chunking
We pick up individual pieces of information and group them into bigger pieces.