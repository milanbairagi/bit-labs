from environment import WumpusWorld
from simple_reflex_agent import SimpleReflexAgent
from model_based_agent import ModelBasedAgent
from goal_based_agent import GoalBasedAgent
from utility_based_agent import UtilityBasedAgent

# Demonstration run
def demo(agent):
    # create environment: size 4x4, sample positions
    env = WumpusWorld(
        size=4,
        pits=[(0,3),(3,1)],
        wumpus=(2,2),

        gold=(1,2),
        agent_pos=(0,0),
        agent_dir="N"
    )
    print("Initial world:")
    print(f"Agent at {env.agent_pos} facing {env.agent_dir}. Gold at {env.gold}, Wumpus at {env.wumpus}, Pits: {env.pits}")
    # env.draw()  #? Uncomment to visualize initial world
    
    print("Running simulation (max 50 steps)...\n")
    for step in range(50):
        p = env.percept()
        print(f"Step {step+1}: Percept -> stench:{p.stench} breeze:{p.breeze} glitter:{p.glitter} bump:{p.bump} scream:{p.scream}")
        act = agent.action(p, env)
        print(f"Agent decides to: {act}")
        result = env.do_action(act)
        # update agent"s internal arrow state if environment used arrow
        agent.has_arrow = env.has_arrow
        if act == "CLIMB" and result == "EXIT":
            print("Agent climbed out. Game End!")
            break
        if not env.agent_alive:
            print("Agent died (fell into pit or encountered live Wumpus). Game End!")
            break
        if env.agent_has_gold and env.agent_pos == (0,0):
            print("Agent has gold and returned to start; agent should CLIMB next turn.")
        if env.scream:
            print("Scream heard: Wumpus has been killed!")
        print(f" -> New pos {env.agent_pos}, facing {env.agent_dir}, has_gold={env.agent_has_gold}, has_arrow={env.has_arrow}\n")
        # env.draw()  #? Uncomment to visualize current world
    else:
        print("Max steps reached.")


if __name__ == "__main__":
    simple_reflex_agent = SimpleReflexAgent()
    model_based_agent = ModelBasedAgent()
    goal_based_agent = GoalBasedAgent()
    utility_based_agent = UtilityBasedAgent()

    print("Simplex Reflex Agent:\n")
    demo(simple_reflex_agent)

    input("\nPress enter to use Model Reflex agent...")

    print("\nModel Reflex Agent:\n")
    demo(model_based_agent)

    input("\nPress enter to use Goal-Based agent...")

    print("\nGoal-Based Agent:\n")
    demo(goal_based_agent)

    input("\nPress enter to use Utility-Based agent...")

    print("\nUtility-Based Agent:\n")
    demo(utility_based_agent)

    print("\n\nProgrammed by Milan Bairagi...")