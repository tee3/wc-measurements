# Measuring I/O performance using a wc-like program

This project explores the performance of several mechanisms for file
input/output in C++ implementing a naive word count program.  The
program explores OS-specific mechanisms (read, mmap), C standard
library mechanisms (fread, fgetc), and C++ standard library mechanisms
(iostreams with std::ifstream::operator<< and std::ifstream::read).

To run all the test and print out the results, run the following
program.  This requires two inputs to be created locally for testing
purposes.  They are not included in the source release since the files
should be large enough to measure the input/output performance.

- `data/files/A*.txt`

     A bunch of files for testing performance across lots of small
     files.

- `data/onefile.txt`

     One large file to measure single-file performance with large
     files.

Note that the results are not identical for the number of words.  The
test programs only look for characters between whitespace, so may have
some false positives.

To build the program without running the test, run the following
command.

```
b2 variant=release cxxflags="-Wextra -Wshadow"
```

To run the test, execute the following command.

```
b2 variant=release --verbose-test cxxflags="-Wextra -Wshadow" test -a
```

# Results

## Many file inputs (185 files, 3.9 MB)

```
$ time wc -w data/files/A*.txt
    1065 data/files/Abraham Lincoln___Lincoln Letters.txt
    3626 data/files/Abraham Lincoln___Lincoln's First Inaugural Address.txt
     299 data/files/Abraham Lincoln___Lincoln's Gettysburg Address, given November 19, 1863.txt
   43640 data/files/Abraham Lincoln___Lincoln's Inaugurals, Addresses and Letters (Selections).txt
     703 data/files/Abraham Lincoln___Lincoln's Second Inaugural Address.txt
       . .
       . .
       . .
 15983065 total

real	0m0.480s
user	0m0.460s
sys		0m0.019s
```

```
$ ./wc_measurements data/files/A*.txt
cstdio_fgetc words: 15983151 (5608.48 ms)
cstdio_fread words: 15982966 (330.045 ms)
iostream_operator words: 15982966 (1377.39 ms)
iostream_read words: 15982966 (752.428 ms)
os_mmap words: 15982966 (360.238 ms)
os_read words: 15982966 (363.41 ms)
```

| Size      | Name |
| --------: | :--------------------------------------------------------------------------------------------------- |
|    5.7 KB | data/files/Abraham Lincoln___Lincoln Letters.txt |
|     21 KB | data/files/Abraham Lincoln___Lincoln's First Inaugural Address.txt |
|    1.6 KB | data/files/Abraham Lincoln___Lincoln's Gettysburg Address, given November 19, 1863.txt |
|    256 KB | data/files/Abraham Lincoln___Lincoln's Inaugurals, Addresses and Letters (Selections).txt |
|    4.0 KB | data/files/Abraham Lincoln___Lincoln's Second Inaugural Address.txt |
|    504 KB | data/files/Abraham Lincoln___Speeches and Letters of Abraham Lincoln, 1832-1865.txt |
|    164 KB | data/files/Abraham Lincoln___State of the Union Addresses.txt |
|    3.8 KB | data/files/Abraham Lincoln___The Emancipation Proclamation.txt |
|     45 KB | data/files/Abraham Lincoln___The Life and Public Service of General Zachary Taylor: An Address.txt |
|    448 KB | data/files/Abraham Lincoln___The Writings of Abraham Lincoln, Volume 1: 1832-1843.txt |
|    493 KB | data/files/Abraham Lincoln___The Writings of Abraham Lincoln, Volume 2: 1843-1858.txt |
|    249 KB | data/files/Abraham Lincoln___The Writings of Abraham Lincoln, Volume 3.txt |
|    205 KB | data/files/Abraham Lincoln___The Writings of Abraham Lincoln, Volume 4.txt |
|    676 KB | data/files/Abraham Lincoln___The Writings of Abraham Lincoln, Volume 5: 1858-1862.txt |
|    587 KB | data/files/Abraham Lincoln___The Writings of Abraham Lincoln, Volume 6: 1862-1863.txt |
|    467 KB | data/files/Abraham Lincoln___The Writings of Abraham Lincoln, Volume 7: 1863-1865.txt |
|    322 KB | data/files/Agatha Christie___The Mysterious Affair at Styles.txt |
|    427 KB | data/files/Agatha Christie___The Secret Adversary.txt |
|    186 KB | data/files/Albert Einstein___Relativity: The Special and General Theory.txt |
|     51 KB | data/files/Albert Einstein___Sidelights on Relativity.txt |
|    329 KB | data/files/Aldous Huxley___Crome Yellow.txt |
|    225 KB | data/files/Aldous Huxley___Mortal Coils.txt |
|     59 KB | data/files/Aldous Huxley___The Defeat of Youth and Other Poems.txt |
|     54 KB | data/files/Alexander Pope___An Essay on Criticism.txt |
|    262 KB | data/files/Alexander Pope___Essay on Man.txt |
|    551 KB | data/files/Alexander Pope___The Poetical Works of Alexander Pope, Volume 1.txt |
|    610 KB | data/files/Alexander Pope___The Poetical Works of Alexander Pope, Volume 2.txt |
|    341 KB | data/files/Alexander Pope___The Rape of the Lock and Other Poems.txt |
|    1.1 MB | data/files/Alexander Pope___The Works of Alexander Pope, Volume 1.txt |
|    619 KB | data/files/Alfred Russel Wallace___Contributions to the Theory of Natural Selection.txt |
|    1.1 MB | data/files/Alfred Russel Wallace___Darwinism.txt |
|    151 KB | data/files/Alfred Russel Wallace___Is Mars Habitable?.txt |
|    1.0 MB | data/files/Alfred Russel Wallace___Island Life.txt |
|    641 KB | data/files/Alfred Russel Wallace___The Malay Archipelago, Volume 1.txt |
|    615 KB | data/files/Alfred Russel Wallace___The Malay Archipelago, Volume 2.txt |
|     89 KB | data/files/Ambrose Bierce___A Cynic Looks at Life.txt |
|     34 KB | data/files/Ambrose Bierce___A Son of the Gods, and A Horseman in the Sky.txt |
|     21 KB | data/files/Ambrose Bierce___An Occurrence at Owl Creek Bridge.txt |
|    273 KB | data/files/Ambrose Bierce___Black Beetles in Amber.txt |
|    337 KB | data/files/Ambrose Bierce___Can Such Things Be?.txt |
|    304 KB | data/files/Ambrose Bierce___Cobwebs From an Empty Skull.txt |
|    165 KB | data/files/Ambrose Bierce___Fantastic Fables.txt |
|     99 KB | data/files/Ambrose Bierce___Present at a Hanging and Other Ghost Stories.txt |
|    278 KB | data/files/Ambrose Bierce___Shapes of Clay.txt |
|    429 KB | data/files/Ambrose Bierce___The Collected Works of Ambrose Bierce, Volume 1.txt |
|    433 KB | data/files/Ambrose Bierce___The Collected Works of Ambrose Bierce, Volume 2.txt |
|    390 KB | data/files/Ambrose Bierce___The Collected Works of Ambrose Bierce, Volume 8.txt |
|     18 KB | data/files/Ambrose Bierce___The Damned Thing.txt |
|    365 KB | data/files/Ambrose Bierce___The Devil's Dictionary.txt |
|    215 KB | data/files/Ambrose Bierce___The Fiend's Delight.txt |
|     42 KB | data/files/Ambrose Bierce___The Parenticide Club.txt |
|    341 KB | data/files/Ambrose Bierce___The Shadow On The Dial, and Other Essays.txt |
|     74 KB | data/files/Ambrose Bierce___Write It Right.txt |
|    260 KB | data/files/Andrew Lang___A Collection of Ballads.txt |
|    556 KB | data/files/Andrew Lang___A Monk of Fife.txt |
|    475 KB | data/files/Andrew Lang___A Short History of Scotland.txt |
|    418 KB | data/files/Andrew Lang___Adventures among Books.txt |
|    326 KB | data/files/Andrew Lang___Alfred Tennyson.txt |
|     66 KB | data/files/Andrew Lang___Andrew Lang's Introduction to The Compleat Angler.txt |
|    185 KB | data/files/Andrew Lang___Angling Sketches.txt |
|     64 KB | data/files/Andrew Lang___Ballads in Blue China and Verses and Translations.txt |
|     60 KB | data/files/Andrew Lang___Ban and Arriere Ban.txt |
|    193 KB | data/files/Andrew Lang___Books and Bookmen.txt |
|    571 KB | data/files/Andrew Lang___Cock Lane and Common-Sense.txt |
|    464 KB | data/files/Andrew Lang___Custom and Myth.txt |
|    329 KB | data/files/Andrew Lang___Essays in Little.txt |
|     70 KB | data/files/Andrew Lang___Grass of Parnassus.txt |
|     83 KB | data/files/Andrew Lang___He.txt |
|    140 KB | data/files/Andrew Lang___Helen of Troy.txt |
|    456 KB | data/files/Andrew Lang___Historical Mysteries.txt |
|    550 KB | data/files/Andrew Lang___Homer and His Age.txt |
|     53 KB | data/files/Andrew Lang___How to Fail in Literature.txt |
|    323 KB | data/files/Andrew Lang___In the Wrong Paradise.txt |
|    442 KB | data/files/Andrew Lang___James VI and the Gowrie Mystery.txt |
|    476 KB | data/files/Andrew Lang___John Knox and the Reformation.txt |
|    177 KB | data/files/Andrew Lang___Letters on Literature.txt |
|    197 KB | data/files/Andrew Lang___Letters to Dead Authors.txt |
|    237 KB | data/files/Andrew Lang___Lost Leaders.txt |
|    333 KB | data/files/Andrew Lang___Modern Mythology.txt |
|     79 KB | data/files/Andrew Lang___Much Darker Days.txt |
|    614 KB | data/files/Andrew Lang___Myth, Ritual And Religion, Vol. 2 (of 2).txt |
|    604 KB | data/files/Andrew Lang___Myth, Ritual, and Religion, Vol. 1.txt |
|     49 KB | data/files/Andrew Lang___New Collected Rhymes.txt |
|    171 KB | data/files/Andrew Lang___Old Friends - Essays in Epistolary Parody.txt |
|    180 KB | data/files/Andrew Lang___Oxford.txt |
|    466 KB | data/files/Andrew Lang___Pickle the Spy.txt |
|    100 KB | data/files/Andrew Lang___Prince Prigio From "His Own Fairy Book".txt |
|     96 KB | data/files/Andrew Lang___Prince Prigio.txt |
|    132 KB | data/files/Andrew Lang___Prince Ricardo of Pantouflia.txt |
|     67 KB | data/files/Andrew Lang___Rhymes a la Mode.txt |
|    392 KB | data/files/Andrew Lang___Shakespeare, Bacon and the Great Unknown.txt |
|    214 KB | data/files/Andrew Lang___Sir Walter Scott and the Border Minstrelsy.txt |
|    492 KB | data/files/Andrew Lang___Tales of Troy and Greece.txt |
|    595 KB | data/files/Andrew Lang___The Arabian Nights Entertainments.txt |
|    727 KB | data/files/Andrew Lang___The Blue Fairy Book.txt |
|    454 KB | data/files/Andrew Lang___The Book of Dreams and Ghosts.txt |
|    507 KB | data/files/Andrew Lang___The Brown Fairy Book.txt |
|    167 KB | data/files/Andrew Lang___The Clyde Mystery.txt |
|    506 KB | data/files/Andrew Lang___The Crimson Fairy Book.txt |
|    596 KB | data/files/Andrew Lang___The Disentanglers.txt |
|     77 KB | data/files/Andrew Lang___The Gold Of Fairnilee.txt |
|    521 KB | data/files/Andrew Lang___The Grey Fairy Book.txt |
|    215 KB | data/files/Andrew Lang___The Library.txt |
|    516 KB | data/files/Andrew Lang___The Lilac Fairy Book.txt |
|    739 KB | data/files/Andrew Lang___The Making of Religion.txt |
|    326 KB | data/files/Andrew Lang___The Mark Of Cain.txt |
|    516 KB | data/files/Andrew Lang___The Orange Fairy Book.txt |
|    509 KB | data/files/Andrew Lang___The Pink Fairy Book.txt |
|     85 KB | data/files/Andrew Lang___The Puzzle of Dickens's Last Plot.txt |
|    651 KB | data/files/Andrew Lang___The Red Fairy Book.txt |
|    502 KB | data/files/Andrew Lang___The Valet's Tragedy and Other Stories.txt |
|    532 KB | data/files/Andrew Lang___The Violet Fairy Book.txt |
|    582 KB | data/files/Andrew Lang___The Yellow Fairy Book.txt |
|     83 KB | data/files/Anthony Trollope___A Ride Across Palestine.txt |
|     63 KB | data/files/Anthony Trollope___Aaron Trow.txt |
|    373 KB | data/files/Anthony Trollope___An Eye for an Eye.txt |
|    387 KB | data/files/Anthony Trollope___An Old Man's Love.txt |
|     62 KB | data/files/Anthony Trollope___An Unprotected Female at the Pyramids.txt |
|    537 KB | data/files/Anthony Trollope___Autobiography of Anthony Trollope.txt |
|    1.1 MB | data/files/Anthony Trollope___Ayala's Angel.txt |
|    1.1 MB | data/files/Anthony Trollope___Barchester Towers.txt |
|    1.7 MB | data/files/Anthony Trollope___Can You Forgive Her?.txt |
|    1.1 MB | data/files/Anthony Trollope___Castle Richmond.txt |
|    375 KB | data/files/Anthony Trollope___Cousin Henry.txt |
|    1.1 MB | data/files/Anthony Trollope___Doctor Thorne.txt |
|    418 KB | data/files/Anthony Trollope___Dr. Wortle's School.txt |
|    1.1 MB | data/files/Anthony Trollope___Framley Parsonage.txt |
|     42 KB | data/files/Anthony Trollope___George Walker At Suez.txt |
|    219 KB | data/files/Anthony Trollope___Harry Heathcote of Gangoil.txt |
|    1.8 MB | data/files/Anthony Trollope___He Knew He Was Right.txt |
|    100 KB | data/files/Anthony Trollope___Hunting Sketches.txt |
|    1.1 MB | data/files/Anthony Trollope___Is He Popenjoy?.txt |
|     53 KB | data/files/Anthony Trollope___John Bull on the Guadalquivir from Tales from all Countries.txt |
|    1.1 MB | data/files/Anthony Trollope___John Caldigate.txt |
|    396 KB | data/files/Anthony Trollope___Kept in the Dark.txt |
|     69 KB | data/files/Anthony Trollope___La Mere Bauche from Tales of All Countries.txt |
|    975 KB | data/files/Anthony Trollope___La Vendée.txt |
|    740 KB | data/files/Anthony Trollope___Lady Anna.txt |
|    682 KB | data/files/Anthony Trollope___Life of Cicero Volume One.txt |
|    698 KB | data/files/Anthony Trollope___Life of Cicero Volume Two.txt |
|    379 KB | data/files/Anthony Trollope___Linda Tressel.txt |
|    1.1 MB | data/files/Anthony Trollope___Marion Fay.txt |
|    755 KB | data/files/Anthony Trollope___Miss Mackenzie.txt |
|     53 KB | data/files/Anthony Trollope___Miss Sarah Jack, of Spanish Town, Jamaica.txt |
|    1.1 MB | data/files/Anthony Trollope___Mr. Scarborough's Family.txt |
|     51 KB | data/files/Anthony Trollope___Mrs. General Talboys.txt |
|    401 KB | data/files/Anthony Trollope___Nina Balatka.txt |
|    773 KB | data/files/Anthony Trollope___North America Volume 1.txt |
|    790 KB | data/files/Anthony Trollope___North America Volume 2.txt |
|    1.6 MB | data/files/Anthony Trollope___Orley Farm.txt |
|    1.4 MB | data/files/Anthony Trollope___Phineas Finn.txt |
|    1.4 MB | data/files/Anthony Trollope___Phineas Redux.txt |
|    766 KB | data/files/Anthony Trollope___Rachel Ray.txt |
|    1.1 MB | data/files/Anthony Trollope___Ralph the Heir.txt |
|     48 KB | data/files/Anthony Trollope___Returning Home.txt |
|    377 KB | data/files/Anthony Trollope___Sir Harry Hotspur of Humblethwaite.txt |
|    361 KB | data/files/Anthony Trollope___Thackeray.txt |
|    1.1 MB | data/files/Anthony Trollope___The American Senator.txt |
|    823 KB | data/files/Anthony Trollope___The Belton Estate.txt |
|    1.2 MB | data/files/Anthony Trollope___The Bertrams.txt |
|     48 KB | data/files/Anthony Trollope___The Chateau of Prince Polignac.txt |
|    1.1 MB | data/files/Anthony Trollope___The Claverings.txt |
|     66 KB | data/files/Anthony Trollope___The Courtship of Susan Bell.txt |
|    1.2 MB | data/files/Anthony Trollope___The Duke's Children.txt |
|    1.4 MB | data/files/Anthony Trollope___The Eustace Diamonds.txt |
|    367 KB | data/files/Anthony Trollope___The Fixed Period.txt |
|    369 KB | data/files/Anthony Trollope___The Golden Lion of Granpere.txt |
|     54 KB | data/files/Anthony Trollope___The House of Heine Brothers, in Munich.txt |
|    980 KB | data/files/Anthony Trollope___The Kellys and the O'Kellys.txt |
|    794 KB | data/files/Anthony Trollope___The Landleaguers.txt |
|    1.8 MB | data/files/Anthony Trollope___The Last Chronicle of Barset.txt |
|    916 KB | data/files/Anthony Trollope___The Macdermots of Ballycloran.txt |
|     64 KB | data/files/Anthony Trollope___The Man Who Kept His Money In A Box.txt |
|     50 KB | data/files/Anthony Trollope___The Mistletoe Bough.txt |
|     41 KB | data/files/Anthony Trollope___The O'Conors of Castle Conor from Tales from all Countries.txt |
|     62 KB | data/files/Anthony Trollope___The Parson's Daughter of Oxney Colne.txt |
|    1.5 MB | data/files/Anthony Trollope___The Prime Minister.txt |
|     44 KB | data/files/Anthony Trollope___The Relics of General Chasse.txt |
|    1.3 MB | data/files/Anthony Trollope___The Small House at Allington.txt |
|    384 KB | data/files/Anthony Trollope___The Struggles of Brown, Jones, and Robinson.txt |
|    1.1 MB | data/files/Anthony Trollope___The Three Clerks.txt |
|    1.1 MB | data/files/Anthony Trollope___The Vicar of Bullhampton.txt |
|    398 KB | data/files/Anthony Trollope___The Warden.txt |
|    1.8 MB | data/files/Anthony Trollope___The Way We Live Now.txt |
|    132 KB | data/files/Arnold Joseph Toynbee___Turkey: A Past and a Future.txt |

## Single file input (1 file, 1.1 GB)

```
$ time wc -w data/onefile.txt
 210915602 data/onefile.txt

real	0m6.137s
user	0m5.929s
sys		0m0.174s
```

```
$ ./wc_measurements data/onefile.txt
cstdio_fgetc words: 210907705 (64491.6 ms)
cstdio_fread words: 210907704 (4897.14 ms)
iostream_operator words: 210907704 (18437.2 ms)
iostream_read words: 210907704 (10479.3 ms)
os_mmap words: 210907704 (4867.94 ms)
os_read words: 210907704 (5370.17 ms)
```

| Size      | Name |
| --------: | :------------------------------------------------------------------------------------------------------ |
|   1.1 GB  | data/onefile.txt |
