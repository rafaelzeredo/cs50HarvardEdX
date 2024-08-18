#include <cs50.h>
#include <stdio.h>
#include <string.h>
// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    int j = 0, candidateNum = 0;
    // TODO
    for (int i = 0 ; i < candidate_count ; i++)
    {

        if (strcmp (candidates[i].name, name) == 0)
        {
            // updating two dimentional array (I learned how to better work with 2D arrays and for loops this watching this video:
            // https://www.youtube.com/watch?v=KJgsSFOSQv0) 3:00:00
            candidateNum = i;
            // Update preferences
            preferences[voter][rank] = candidateNum;
            //printf("Candidate number is %i \n", preferences[voter][rank-1]);
            return true;
        }
    }

    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    int i = 0, j = 0, candidateNum = 0, candidatesUpdated = 0, eliminated = 0;
    // Iterate through all voters checking if their first preference is valid
    for (i = 0; i < voter_count ; i++)
    {
        // Iterate through all candidates checking if they are valid yet for update
        // If the candidate has been eliminated then go to next candidate preference for that voter
        if (candidates[j].eliminated == true)
        {
            while (candidates[j].eliminated == true)
            {
                printf("Candidate %s has been eliminated, now j is %i\n", candidates[j].name, j + 1);
                j++;
                //eliminated++;
            }
        }
        // If the candidate has not been eliminated then update the candidate's votes according to preferences
        if (candidates[j].eliminated == false)
        {
            candidateNum = preferences[i][j];
            candidates[candidateNum].votes++;
            candidatesUpdated++;
            printf("candidate %i has %i votes\n", candidateNum, candidates[candidateNum].votes);
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    int halfTotalVotes = (voter_count/2);
    printf("half the vote is %i\n", halfTotalVotes);
    for (int i = 0 ; i < candidate_count ; i++)
    {
        if (candidates[i].votes > halfTotalVotes)
        {

            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    // First I'll create a variable that holds the minimum value. I'll make it higher than the max vote count
    int min = 101;
    // Iterate through the candidates comparing their votes
    for (int i = 0 ; i < candidate_count ; i++)
    {
        if (candidates[i].eliminated == false)
        {
            if (candidates[i].votes < 101)
            {
               min = candidates[i].votes;
            }
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    // First I iterate through all candidates to find who has the highest votes.
    int j = 0, highestVote = 0, validCandidate_count = 0, winners = 0, ties = 0;
    for (int i = 0 ; i < candidate_count ; i++)
    {
        // If the candidate is not eliminated I will count him as valid
        if (candidates[i].eliminated == false)
        {
            validCandidate_count++;
            // If candidate's votes are higher than highest votes variable update the variable
            if (candidates[i].votes > highestVote)
            {
                highestVote = candidates[i].votes;
            }
        }

    }
    // Make the tie work for all valid candidates with votes equal to highest number of votes variable
    for (int i = 0 ; i < candidate_count ; i++)
    {
        if (candidates[i].votes == highestVote)
        {
            winners++;
        }
    }
    if (winners == validCandidate_count)
    {
        printf("It's a tie\n");
        return true;
    }
    printf("Not tied\n");
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    // Iterate through all candidates
    for (int i = 0 ; i < candidate_count ; i++)
    {
        if (candidates[i].eliminated == false)
        {
            if (candidates[i].votes == min)
            {
                candidates[i].eliminated = true;
                printf("candidate %s eliminated\n", candidates[i].name);
            }
        }
    }
    return;
}