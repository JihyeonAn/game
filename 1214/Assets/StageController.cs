using UnityEngine;
using UnityEngine.SceneManagement;

public class StageController : MonoBehaviour
{
    [SerializeField]
    private string nextSceneName;
    [SerializeField]
    private GameObject panelStageClear;
    private int maxCoinCount;
    private int currentCoinCount;
    private bool getAllCoins = false;

    public int MaxCoinCount => maxCoinCount;
    public int CurrentCoinCount => currentCoinCount;

    private void Awake()
    {
        Time.timeScale = 1.0f;

        panelStageClear.SetActive(false);

        maxCoinCount = GameObject.FindGameObjectsWithTag("Coin").Length;
        currentCoinCount = maxCoinCount;
    }

    private void Update()
    {
        if (getAllCoins==true) 
        {
            if (Input.GetKeyDown(KeyCode.Return))
            {
                SceneManager.LoadScene(nextSceneName);
            }
        }
    }
    public void GetCoin()
    {
        currentCoinCount--;

        if(currentCoinCount == 0)
        {
            getAllCoins = true;

            Time.timeScale = 0.0f;

            panelStageClear.SetActive(true);
        }
    }
}
