#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            int pref_cand = ranks[i];
            int less_cand = ranks[j];

            preferences[pref_cand][less_cand] += 1;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            int candid_i = i;
            int candid_j = j;

            if (preferences[candid_i][candid_j] == preferences[candid_j][candid_i])
            {
                continue;
            }
            else if (preferences[candid_i][candid_j] > preferences[candid_j][candid_i])
            {
                pairs[pair_count].winner = candid_i;
                pairs[pair_count].loser = candid_j;

                pair_count++;
            }
            else
            {
                pairs[pair_count].winner = candid_j;
                pairs[pair_count].loser = candid_i;

                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        int winner_i = pairs[i].winner;
        int loser_i = pairs[i].loser;
        int strength_victory_i = preferences[winner_i][loser_i] - preferences[loser_i][winner_i];

        for (int j = i + 1; j < pair_count; j++)
        {
            int winner_j = pairs[j].winner;
            int loser_j = pairs[j].loser;
            int strength_victory_j = preferences[winner_j][loser_j] - preferences[loser_j][winner_j];

            if (strength_victory_i == strength_victory_j || strength_victory_i > strength_victory_j)
            {
                continue;
            }
            else
            {
                pairs[i].winner = winner_j;
                pairs[i].loser = loser_j;

                pairs[j].winner = winner_i;
                pairs[j].loser = loser_i;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;

        // verificação para nao criar ciclo
        int temp_winner = winner;
        int x = 0;
        bool no_cycle = true;
        while (no_cycle)
        {
            bool found = false;

            for (int j = 0; j < candidate_count; j++)
            {
                if (locked[j][temp_winner])
                {
                    temp_winner = j;
                    found = true;
                }
            }

            if (!found)
            {
                break;
            }
            else if (temp_winner == loser)
            {
                no_cycle = false;
            }
        }

        if (no_cycle)
        {
            locked[winner][loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    for (int colun = 0; colun < candidate_count; colun++)
    {
        bool edge = false;

        for (int row = 0; row < candidate_count; row++)
        {
            if (locked[row][colun])
            {
                edge = true;
                break;
            }
        }

        if (!edge)
        {
            printf("%s\n", candidates[colun]);
        }
    }
    return;
}